#!/bin/bash
#
# This script will export all of the required header files and static libraries necessary to run tensorflow on iOS
#

read -p "Bucket name [ever-ai]: " BUCKET_NAME
BUCKET_NAME="${BUCKET_NAME:-ever-ai}"

read -p "Model name: " MODEL_NAME

VERSION=`(git describe HEAD --tags --abbrev=0 || echo "[[VERSION]]") | sed -e "s/^v//"`
read -p "Tensorflow version [$VERSION]: " INPUT_VERSION
VERSION="${INPUT_VERSION:-$VERSION}"

EXPORT_DIRECTORY=./tensorflow_export


# Cleanup existing $EXPORT_DIRECTORY
rm -rf $EXPORT_DIRECTORY

# Create folders we need for export
mkdir -p $EXPORT_DIRECTORY/include
mkdir -p $EXPORT_DIRECTORY/include/third_party/eigen3/unsupported/Eigen
mkdir -p $EXPORT_DIRECTORY/include/third_party/eigen3/Eigen
mkdir -p $EXPORT_DIRECTORY/lib


echo "Preparing files..."

# Copy all of the header files we need (preserving their paths)
# Destination: $EXPORT_DIRECTORY/include
rsync -a --include '*/' --include '*.h' --exclude '*' ./tensorflow/contrib/makefile/downloads/protobuf/src/google/* $EXPORT_DIRECTORY/include/google
# rsync -a --include '*/' --include '*.h' --exclude '*' ./tensorflow/contrib/makefile/downloads/* $EXPORT_DIRECTORY/include
rsync -a --include '*/' --include '*.h' --exclude '*' ./tensorflow/contrib/makefile/gen/proto/* $EXPORT_DIRECTORY/include
rsync -a --include '*/' --include '*.h' --exclude '*' ./tensorflow/core $EXPORT_DIRECTORY/include/tensorflow/
rsync -a -R --include '*' ./third_party/eigen3/unsupported/Eigen $EXPORT_DIRECTORY/include
rsync -a --include '*' ./tensorflow/contrib/makefile/downloads/eigen/unsupported/Eigen/* $EXPORT_DIRECTORY/include/third_party/eigen3/unsupported/Eigen
rsync -a --include '*' ./tensorflow/contrib/makefile/downloads/eigen/Eigen/* $EXPORT_DIRECTORY/include/third_party/eigen3/Eigen
rsync -a --include '*' ./tensorflow/contrib/makefile/downloads/nsync/public/* $EXPORT_DIRECTORY/include/third_party/nsync/

# Copy the built static libraries we need
# Destination: $EXPORT_DIRECTORY/lib
cp tensorflow/contrib/makefile/gen/lib/libtensorflow-core.a $EXPORT_DIRECTORY/lib/libtensorflow-core-eai.a
cp tensorflow/contrib/makefile/gen/protobuf_ios/lib/libprotobuf-lite.a $EXPORT_DIRECTORY/lib/libprotobuf-lite-eai.a
cp tensorflow/contrib/makefile/gen/protobuf_ios/lib/libprotobuf.a $EXPORT_DIRECTORY/lib/libprotobuf-eai.a
cp tensorflow/contrib/makefile/downloads/nsync/builds/lipo.ios.c++11/nsync.a $EXPORT_DIRECTORY/lib/nsync-eai.a

cd $EXPORT_DIRECTORY

cat ../tensorflow/core/framework/ops_to_register.h | grep "|| isequal(op," | sed -E 's/.*"(.+)".*/\1/g' > supported_ops.txt

echo "Creating archive..."
zip -rq tensorflow.zip ./*

PODSPEC_FILENAME="Tensorflow-$MODEL_NAME.podspec"

cp ../Tensorflow-ever-ai.podspec "$PODSPEC_FILENAME"
sed -i '' "s/model = \"[^\"]*\"/model = \"$MODEL_NAME\"/" "$PODSPEC_FILENAME"
sed -i '' "s/bucket = \"[^\"]*\"/bucket = \"$BUCKET_NAME\"/" "$PODSPEC_FILENAME"
sed -i '' -E "s/(.*\.version[[:space:]]*=[[:space:]]*)\"[^\"]*\"/\\1\"$VERSION\"/" "$PODSPEC_FILENAME"

# echo "*******************************************************************************************"
# echo "*                                                                                         *"
# echo "*                                   Done Exporting                                        *"
# echo "*                                                                                         *"
# echo "*   Make sure to check that libtensorflow-core-eai.a is in $EXPORT_DIRECTORY/lib          *"
# echo "*   This file is .gitignored in this repo because it is >400MB                            *"
# echo "*   If you haven't just rebuilt tensorflow from source you may need to manually add it.   *"
# echo "*                                                                                         *"
# echo "*******************************************************************************************"
# echo ""

if [ "$BUCKET_NAME" = "ever-ai" ]; then
    if [ "$MODEL_NAME" = "" ]; then
        MODEL_PATH=""
    else
        MODEL_PATH="/$MODEL_NAME"
    fi
    echo "Uploading to S3... (s3://ever-ai/ios/tensorflow$MODEL_PATH/$VERSION/tensorflow.zip)"
    aws s3 cp tensorflow.zip "s3://ever-ai/ios/tensorflow$MODEL_PATH/$VERSION/tensorflow.zip" --acl public-read
    aws s3 cp supported_ops.txt "s3://ever-ai/ios/tensorflow$MODEL_PATH/$VERSION/supported_ops.txt" --acl public-read
    echo "Pushing Podspec to ever-ai Specs repo..."
    pod repo push --allow-warnings --skip-import-validation ever-ai "$PODSPEC_FILENAME"
elif [ "$BUCKET_NAME" = "download.everalbum.com" ]; then
    echo "Uploading to S3... (s3://download.everalbum.com/ios/deps/tensorflow/$VERSION/tensorflow.zip)"
    aws s3 cp tensorflow.zip "s3://download.everalbum.com/ios/deps/tensorflow/$VERSION/tensorflow.zip" --acl public-read
    aws s3 cp supported_ops.txt "s3://download.everalbum.com/ios/deps/tensorflow/$VERSION/supported_ops.txt" --acl public-read
    echo "Pushing Podspec to everalbum Specs repo..."
    pod repo push --allow-warnings --skip-import-validation everalbum "$PODSPEC_FILENAME"
else
    echo "Updated:"
    echo "    $EXPORT_DIRECTORY/$PODSPEC_FILENAME"
    echo "which you can lint via:"
    echo "    pod spec lint --quick --private \"$EXPORT_DIRECTORY/$PODSPEC_FILENAME\""
    echo "and you'll want to add the podspec to the Specs repo under:"
    echo "    Tensorflow-$MODEL_NAME/$VERSION/$PODSPEC_FILENAME"
fi

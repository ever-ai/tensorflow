#!/bin/bash
#
# This script will export all of the required header files and static libraries necessary to run tensorflow on iOS
#

EXPORT_DIRECTORY=./tensorflow_export
VERSION=`(git describe HEAD --tags --abbrev=0 || echo "[[VERSION]]") | sed -e "s/^v//"`

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

echo "Creating archive..."

cd $EXPORT_DIRECTORY
zip -rq tensorflow.zip ./*

echo "*******************************************************************************************"
echo "*                                                                                         *"
echo "*                                   Done Exporting                                        *"
echo "*                                                                                         *"
echo "*   Make sure to check that libtensorflow-core-eai.a is in $EXPORT_DIRECTORY/lib          *"
echo "*   This file is .gitignored in this repo because it is >400MB                            *"
echo "*   If you haven't just rebuilt tensorflow from source you may need to manually add it.   *"
echo "*                                                                                         *"
echo "*******************************************************************************************"
echo ''
echo "Upload to S3 using:"
echo "aws s3 cp $EXPORT_DIRECTORY/tensorflow.zip \\"
echo "    \"s3://download.everalbum.com/ios/deps/tensorflow/$VERSION/tensorflow.zip\" --acl public-read"
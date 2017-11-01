#
# This script will export all of the required header files and static libraries necessary to run tensorflow on iOS
#
clear

EXPORT_DIRECTORY=./tensorflow_export

# Cleanup existing $EXPORT_DIRECTORY
rm -rf $EXPORT_DIRECTORY

# Create folders we need for export
mkdir -p $EXPORT_DIRECTORY/include
mkdir -p $EXPORT_DIRECTORY/lib

# Copy all of the header files we need (preserving their paths)
# Destination: $EXPORT_DIRECTORY/include
rsync -a -R --include '*/' --include '*.h' --exclude '*' ./tensorflow/contrib/makefile/downloads $EXPORT_DIRECTORY/include
rsync -a -R --include '*/' --include '*.h' --exclude '*' ./tensorflow/contrib/makefile/gen/proto $EXPORT_DIRECTORY/include
rsync -a -R --include '*/' --include '*.h' --exclude '*' ./tensorflow/core $EXPORT_DIRECTORY/include
rsync -a -R --include '*' ./third_party/eigen3/unsupported/Eigen $EXPORT_DIRECTORY/include
rsync -a -R --include '*' ./tensorflow/contrib/makefile/downloads/eigen/unsupported/Eigen $EXPORT_DIRECTORY/include
rsync -a -R --include '*' ./tensorflow/contrib/makefile/downloads/eigen/Eigen $EXPORT_DIRECTORY/include

# Copy the built static libraries we need
# Destination: $EXPORT_DIRECTORY/lib
cp tensorflow/contrib/makefile/gen/lib/libtensorflow-core.a $EXPORT_DIRECTORY/lib/libtensorflow-core-eai.a 
cp tensorflow/contrib/makefile/gen/protobuf_ios/lib/libprotobuf-lite.a $EXPORT_DIRECTORY/lib/libprotobuf-lite-eai.a
cp tensorflow/contrib/makefile/gen/protobuf_ios/lib/libprotobuf.a $EXPORT_DIRECTORY/lib/libprotobuf-eai.a

echo "*******************************************************************************************"
echo "*                                                                                         *"
echo "*                                   Done Exporting                                        *"
echo "*                                                                                         *"
echo "*   Make sure to check that libtensorflow-core-eai.a is in $EXPORT_DIRECTORY/lib          *"
echo "*   This file is .gitignored in this repo because it is >400MB                            *"
echo "*   If you haven't just rebuilt tensorflow from source you may need to manually add it.   *"
echo "*                                                                                         *"
echo "*******************************************************************************************"
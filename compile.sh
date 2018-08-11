#! /usr/bin/env bash

set -e

archs=(x86 x86_64 armeabi-v7a arm64-v8a)
graphs=$(find ~/models -regex '.*/*_\(frozen\|optimized\|quantized\).pb')

function join_by { local d=$1; shift; echo -n "$1"; shift; printf "%s" "${@/#/$d}"; }

bazel build tensorflow/python/tools/print_selective_registration_header
bazel-bin/tensorflow/python/tools/print_selective_registration_header --graphs="$(join_by , ${graphs[@]})" > tensorflow/core/framework/ops_to_register.h

for arch in "${archs[@]}"
do
	case "$arch" in
        armeabi-v7a)
		march="--copt=-march=armv7-a"
		;;
        arm64-v8a)
		march="--copt=-march=armv8-a"
		;;
 	*)
		march=""
	esac

	bazel build \
		--copt=-DSELECTIVE_REGISTRATION \
		--copt=-DSUPPORT_SELECTIVE_REGISTRATION \
		--host_crosstool_top=@bazel_tools//tools/cpp:toolchain \
		--crosstool_top=//external:android/crosstool \
		--cpu=$arch \
		--verbose_failures \
		$march \
		//tensorflow/contrib/android:libtensorflow_inference.so

	gsutil cp bazel-bin/tensorflow/contrib/android/libtensorflow_inference.so gs://everai-mailbox/libtensorflow_inference-$arch.so
done

bazel \
	--host_javabase=/usr/lib/jvm/java-8-openjdk-amd64 \
	build \
	//tensorflow/contrib/android:android_tensorflow_inference_java
gsutil cp bazel-bin/tensorflow/contrib/android/libandroid_tensorflow_inference_java.jar gs://everai-mailbox/

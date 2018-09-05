load("//tensorflow:tensorflow.bzl", "tf_cc_shared_object")

tf_cc_shared_object(
    name = "libeverai.so",
    srcs = [
        "model.h",
        "sdk.h",
        "model.cc",
        "sdk.cc",
        ],
    deps = [
        "//tensorflow/cc/saved_model:loader",
        "//tensorflow/cc/saved_model:tag_constants",
        "//tensorflow/cc/saved_model:signature_constants",
        "//tensorflow/contrib/image:image_ops_cc",
        ],
    )

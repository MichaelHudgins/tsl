load("@bazel_skylib//:bzl_library.bzl", "bzl_library")

package(
    default_visibility = [
        "//third_party/tensorflow:__subpackages__",
    ],
    licenses = ["notice"],
)

# mkl_dnn license placeholder

config_setting(
    name = "build_with_mkl_opensource",
    define_values = {
        "build_with_mkl": "true",
        "build_with_mkl_opensource": "true",
    },
    visibility = ["//visibility:public"],
)

config_setting(
    name = "build_with_mkldnn_openmp",
    define_values = {
        "build_with_mkl": "true",
        "build_with_openmp": "true",
    },
    visibility = ["//visibility:public"],
)

config_setting(
    name = "build_with_mkl_aarch64_openmp",
    define_values = {
        "build_with_mkl_aarch64": "true",
        "build_with_openmp": "true",
    },
    visibility = ["//visibility:public"],
)

config_setting(
    name = "build_with_mkl_aarch64",
    define_values = {
        "build_with_mkl_aarch64": "true",
    },
    visibility = ["//visibility:public"],
)

bzl_library(
    name = "build_defs_bzl",
    srcs = ["build_defs.bzl"],
)

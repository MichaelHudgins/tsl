# Description:
#   Stubs for dynamically loading CUDA.

load(
    "//tsl/platform/default:cuda_build_defs.bzl",
    "if_cuda_is_configured",
)
load(
    "//tsl/platform:build_config.bzl",
    "tsl_cc_test",
)
load(
    "//tsl/platform:rules_cc.bzl",
    "cc_library",
)

package(
    licenses = ["notice"],
)

cc_library(
    name = "cublas_stub",
    srcs = if_cuda_is_configured(["cublas_stub.cc"]),
    textual_hdrs = glob(["cublas_*.inc"]),
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        "//third_party/gpus/cuda:cuda_headers",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

alias(
    name = "cublas_lib",
    actual = select({
        "//tsl:oss": ":cublas_stub",
        "//conditions:default": "//third_party/gpus/cuda:cublas_static",
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cublas_lt_stub",
    srcs = if_cuda_is_configured(["cublasLt_stub.cc"]),
    textual_hdrs = glob(["cublasLt_*.inc"]),
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        "//third_party/gpus/cuda:cuda_headers",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

alias(
    name = "cublas_lt_lib",
    actual = select({
        "//tsl:oss": ":cublas_lt_stub",
        "//conditions:default": "//third_party/gpus/cuda:cublas_lt_static",
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cuda_stub",
    srcs = if_cuda_is_configured(["cuda_stub.cc"]),
    textual_hdrs = glob(["cuda_*.inc"]),
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        "//third_party/gpus/cuda:cuda_headers",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

cc_library(
    name = "cudart_stub",
    srcs = select({
        # include dynamic loading implementation only when if_cuda_is_configured and build dynamically
        "//tsl:is_cuda_enabled_and_oss": ["cudart_stub.cc"],
        "//conditions:default": [],
    }),
    textual_hdrs = glob(["cuda_runtime_*.inc"]),
    visibility = ["//visibility:public"],
    deps = select({
        "//tsl:is_cuda_enabled_and_oss": [
            ":cuda_stub",
            "//third_party/gpus/cuda:cuda_headers",
            "//tsl/platform:dso_loader",
            "//tsl/platform:env",
        ],
        "//conditions:default": [],
    }),
)

filegroup(
    name = "cudnn_wrappers",
    srcs = glob(["cudnn_*.inc"]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cudnn_stub",
    srcs = if_cuda_is_configured(["cudnn_stub.cc"]),
    textual_hdrs = glob(["cudnn_*.inc"]),
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        ":cudnn_version",
        "//third_party/gpus/cudnn:cudnn_header",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

alias(
    name = "cudnn_lib",
    actual = select({
        "//tsl:oss": ":cudnn_stub",
        "//conditions:default": "//third_party/gpus/cudnn:cudnn",
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cudnn_version",
    srcs = ["cudnn_version.cc"],
    hdrs = ["cudnn_version.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_absl//absl/strings",
    ],
)

tsl_cc_test(
    name = "cudnn_version_test",
    srcs = ["cudnn_version_test.cc"],
    deps = [
        ":cudnn_version",
        "//tsl/platform:test",
        "//tsl/platform:test_main",
    ],
)

cc_library(
    name = "cufft_stub",
    srcs = if_cuda_is_configured(["cufft_stub.cc"]),
    textual_hdrs = glob(["cufft_*.inc"]),
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        "//third_party/gpus/cuda:cuda_headers",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

alias(
    name = "cufft_lib",
    actual = select({
        "//tsl:oss": ":cufft_stub",
        "//conditions:default": "//third_party/gpus/cuda:cufft_static",
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cupti_stub",
    srcs = if_cuda_is_configured(["cupti_stub.cc"]),
    data = if_cuda_is_configured(["//third_party/gpus/cuda:cupti_dsos"]),
    textual_hdrs = ["cupti_10_0.inc"],
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        "//third_party/gpus/cuda:cuda_headers",
        "//third_party/gpus/cuda:cupti_headers",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

cc_library(
    name = "curand_stub",
    srcs = if_cuda_is_configured(["curand_stub.cc"]),
    textual_hdrs = ["curand_10_0.inc"],
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        "//third_party/gpus/cuda:cuda_headers",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

alias(
    name = "curand_lib",
    actual = select({
        "//tsl:oss": ":curand_stub",
        "//conditions:default": "//third_party/gpus/cuda:curand_static",
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cusolver_stub",
    srcs = if_cuda_is_configured(["cusolver_stub.cc"]),
    textual_hdrs = glob(["cusolver_dense_*.inc"]),
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        "//third_party/gpus/cuda:cuda_headers",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

alias(
    name = "cusolver_lib",
    actual = select({
        "//tsl:oss": ":cusolver_stub",
        "//conditions:default": "//third_party/gpus/cuda:cusolver_static",
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "cusparse_stub",
    srcs = if_cuda_is_configured(["cusparse_stub.cc"]),
    textual_hdrs = glob(["cusparse_*.inc"]),
    visibility = ["//visibility:public"],
    deps = if_cuda_is_configured([
        "//third_party/gpus/cuda:cuda_headers",
        "//tsl/platform:dso_loader",
        "//tsl/platform:env",
    ]),
)

alias(
    name = "cusparse_lib",
    actual = select({
        "//tsl:oss": ":cusparse_stub",
        "//conditions:default": "//third_party/gpus/cuda:cusparse_static",
    }),
    visibility = ["//visibility:public"],
)

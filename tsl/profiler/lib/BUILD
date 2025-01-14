load("//tsl/platform:rules_cc.bzl", "cc_library")
load("//tsl/platform:build_config_root.bzl", "if_static")
load("//tsl:tsl.default.bzl", "filegroup")
load("//third_party/tensorflow:tensorflow.bzl", "if_not_android", "tf_cc_test")
load(
    "//tsl/profiler/builds:build_config.bzl",
    "tf_profiler_copts",
)

cc_library(
    name = "context_types_hdrs",
    hdrs = ["context_types.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "context_types",
    srcs = ["context_types.cc"],
    hdrs = ["context_types.h"],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "mobile_srcs_no_runtime",
    srcs = [
        "scoped_annotation.h",
        "traceme.h",
        "traceme_encode.h",
    ],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "mobile_srcs_only_runtime",
    srcs = [
        "context_types.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "profiler_controller",
    srcs = ["profiler_controller.cc"],
    hdrs = ["profiler_controller.h"],
    visibility = [
        "//third_party/tensorflow/core/profiler/lib:__pkg__",
    ],
    deps = [
        ":profiler_interface",
        "//third_party/tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tsl/platform:errors",
        "//tsl/platform:logging",
        "//tsl/platform:status",
    ],
)

cc_library(
    name = "profiler_factory",
    hdrs = ["profiler_factory.h"],
    visibility = [
        "//third_party/tensorflow/core/profiler/lib:__pkg__",
    ],
    deps = [
        ":profiler_interface",
        "//third_party/tensorflow/core/profiler:profiler_options_proto_cc",
    ] + if_static([
        ":profiler_factory_impl",
    ]),
)

cc_library(
    name = "profiler_factory_impl",
    srcs = [
        "profiler_factory.cc",
        "profiler_factory.h",
    ],
    copts = tf_profiler_copts(),
    visibility = [
        "//third_party/tensorflow/core/profiler:__pkg__",
        "//third_party/tensorflow/core/profiler/lib:__pkg__",
    ],
    deps = [
        ":profiler_interface",
        "//third_party/tensorflow/core/profiler:profiler_options_proto_cc",
        "//third_party/tensorflow/core/profiler/lib:profiler_controller",
        "//tsl/platform:mutex",
    ],
    alwayslink = True,
)

tf_cc_test(
    name = "profiler_factory_test",
    srcs = ["profiler_factory_test.cc"],
    deps = [
        ":profiler_factory",
        ":profiler_interface",
        "//third_party/tensorflow/core:protos_all_cc",
        "//third_party/tensorflow/core:test",
        "//third_party/tensorflow/core:test_main",
        "//third_party/tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tsl/platform:macros",
        "//tsl/platform:status",
        "@com_google_absl//absl/memory",
    ],
)

cc_library(
    name = "profiler_interface",
    hdrs = ["profiler_interface.h"],
    copts = tf_profiler_copts(),
    visibility = [
        "//third_party/tensorflow/core/profiler:internal",
        "//tsl:internal",
    ],
    deps = [
        "//third_party/tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tsl/platform:status",
    ],
)

cc_library(
    name = "profiler_lock",
    srcs = ["profiler_lock.cc"],
    hdrs = ["profiler_lock.h"],
    copts = tf_profiler_copts(),
    visibility = ["//third_party/tensorflow/core/profiler:internal"],
    deps = [
        "//third_party/tensorflow/core:lib",
        "//third_party/tensorflow/core:lib_internal",
    ],
)

tf_cc_test(
    name = "profiler_lock_test",
    srcs = ["profiler_lock_test.cc"],
    deps = [
        ":profiler_lock",
        "//third_party/tensorflow/core:test",
        "//third_party/tensorflow/core:test_main",
    ],
)

cc_library(
    name = "traceme_encode",
    hdrs = ["traceme_encode.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//tsl/platform:logging",
        "//tsl/platform:macros",
        "@com_google_absl//absl/strings",
    ],
)

tf_cc_test(
    name = "traceme_encode_test",
    srcs = ["traceme_encode_test.cc"],
    deps = [
        ":traceme_encode",
        "//tsl/platform",
        "//tsl/platform:test",
        "//tsl/platform:test_main",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "traceme",
    hdrs = ["traceme.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":traceme_encode",
        "@com_google_absl//absl/strings",
        "//tsl/platform",
        "//tsl/platform:logging",
        "//tsl/platform:macros",
        "//tsl/platform:types",
    ] + if_not_android([
        "//tsl/profiler/backends/cpu:traceme_recorder",
        "//tsl/profiler/utils:time_utils",
    ]),
)

cc_library(
    name = "scoped_annotation",
    hdrs = ["scoped_annotation.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_absl//absl/strings",
        "//tsl/platform:types",
    ] + if_not_android([
        "//tsl/profiler/backends/cpu:annotation_stack",
    ]),
)

cc_library(
    name = "scoped_annotation_stack",
    hdrs = ["scoped_annotation_stack.h"],
    visibility = [
        "//third_party/tensorflow/compiler/xla:runtime",
        "//third_party/tensorflow/core/profiler/lib:__pkg__",
    ],
    deps = [
        "@com_google_absl//absl/strings",
    ] + if_not_android([
        "//tsl/profiler/backends/cpu:annotation_stack",
    ]),
)

tf_cc_test(
    name = "scoped_annotation_test",
    size = "small",
    srcs = ["scoped_annotation_test.cc"],
    deps = [
        ":scoped_annotation",
        ":scoped_annotation_stack",
        "//tsl/platform:test",
        "//tsl/platform:test_benchmark",
        "//tsl/platform:test_main",
        "//tsl/profiler/backends/cpu:annotation_stack",
        "@com_google_absl//absl/strings",
    ],
)

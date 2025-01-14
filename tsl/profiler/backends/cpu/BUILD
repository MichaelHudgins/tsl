load("//tsl/platform:build_config_root.bzl", "if_static")
load("//tsl/platform:rules_cc.bzl", "cc_library")
load("//tsl/profiler/builds:build_config.bzl", "tf_profiler_copts")
load("//third_party/tensorflow:tensorflow.bzl", "tf_cc_test")

cc_library(
    name = "traceme_recorder",
    hdrs = ["traceme_recorder.h"],
    copts = tf_profiler_copts(),
    visibility = [
        "//third_party/tensorflow/core/profiler:internal",
        "//tsl/profiler:internal",
    ],
    deps = [
        "@com_google_absl//absl/container:flat_hash_map",
        "//tsl/platform:macros",
        "//tsl/platform:mutex",
        "//tsl/platform:thread_annotations",
        "//tsl/platform:types",
    ] + if_static([
        ":traceme_recorder_impl",
    ]),
)

cc_library(
    name = "traceme_recorder_impl",
    srcs = [
        "traceme_recorder.cc",
    ],
    hdrs = ["traceme_recorder.h"],
    copts = tf_profiler_copts(),
    visibility = [
        "//third_party/tensorflow/compiler/xla/stream_executor:__subpackages__",
        "//third_party/tensorflow/core/profiler:__pkg__",
        "//third_party/tensorflow/core/profiler/backends/cpu:__pkg__",
        "//third_party/tensorflow/python:__pkg__",
        "//tsl/platform/cloud:__pkg__",
        "//tsl/profiler:__pkg__",
    ],
    deps = [
        "//tsl/platform:env",
        "//tsl/platform:logging",
        "//tsl/platform:macros",
        "//tsl/platform:mutex",
        "//tsl/platform:thread_annotations",
        "//tsl/platform:types",
        "@com_google_absl//absl/container:flat_hash_map",
    ],
    alwayslink = True,
)

tf_cc_test(
    name = "traceme_recorder_test",
    srcs = ["traceme_recorder_test.cc"],
    deps = [
        ":traceme_recorder",
        "//tsl/platform:env",
        "//tsl/platform:env_impl",
        "//tsl/platform:logging",
        "//tsl/platform:notification",
        "//tsl/platform:test",
        "//tsl/platform:test_main",
        "//tsl/platform:types",
        "//tsl/profiler/utils:math_utils",
        "//tsl/profiler/utils:time_utils",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "annotation_stack",
    hdrs = ["annotation_stack.h"],
    copts = tf_profiler_copts(),
    visibility = [
        "//tsl/profiler:internal",
    ],
    deps = [
        "@com_google_absl//absl/strings",
        "//tsl/platform:macros",
        "//tsl/platform:types",
    ] + if_static([
        ":annotation_stack_impl",
    ]),
)

cc_library(
    name = "annotation_stack_impl",
    srcs = [
        "annotation_stack.cc",
        "annotation_stack.h",
    ],
    copts = tf_profiler_copts(),
    visibility = [
        "//third_party/tensorflow/core/profiler/backends/cpu:__pkg__",
        "//tsl/profiler:__pkg__",
    ],
    deps = [
        "//tsl/platform:macros",
        "//tsl/platform:types",
        "@com_google_absl//absl/strings",
    ],
    alwayslink = True,
)

cc_library(
    name = "host_tracer_utils",
    srcs = ["host_tracer_utils.cc"],
    hdrs = ["host_tracer_utils.h"],
    copts = tf_profiler_copts(),
    visibility = [
        "//third_party/tensorflow/core/profiler:internal",
        "//tsl/profiler:internal",
    ],
    deps = [
        ":traceme_recorder",
        "//third_party/tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tsl/platform:types",
        "//tsl/profiler/utils:parse_annotation",
        "//tsl/profiler/utils:tf_op_utils",
        "//tsl/profiler/utils:xplane_builder",
        "//tsl/profiler/utils:xplane_utils",
        "@com_google_absl//absl/strings",
    ],
)

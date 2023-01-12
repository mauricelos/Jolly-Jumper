load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "jolly_jumper",
    srcs = ["src/jolly_jumper.cpp"],
    hdrs = [
        "include/jolly_jumper.h",
    ],
    copts = select({
        "@bazel_tools//src/conditions:windows": ["/std:c++17"],
        "//conditions:default": ["-std=c++17"],
    }),
    includes = ["include"],
    linkopts = select({
        "@bazel_tools//src/conditions:windows": [],
        "@bazel_tools//src/conditions:darwin": [],
        "//conditions:default": [
            "-std=c++17",
            "-lstdc++fs",
        ],
    }),
    strip_include_prefix = "include",
)

cc_binary(
    name = "jolly_jumper_main",
    srcs = ["src/main.cpp"],
    copts = select({
        "@bazel_tools//src/conditions:windows": ["/std:c++17"],
        "//conditions:default": ["-std=c++17"],
    }),
    linkopts = select({
        "@bazel_tools//src/conditions:windows": [],
        "@bazel_tools//src/conditions:darwin": [],
        "//conditions:default": [
            "-std=c++17",
            "-lstdc++fs",
        ],
    }),
    deps = [
        ":jolly_jumper",
    ],
)

cc_test(
    name = "jolly_jumper_test",
    srcs = ["test/jolly_jumper_test.cpp"],
    copts = select({
        "@bazel_tools//src/conditions:windows": ["/std:c++17"],
        "//conditions:default": ["-std=c++17"],
    }),
    linkopts = select({
        "@bazel_tools//src/conditions:windows": [],
        "@bazel_tools//src/conditions:darwin": [],
        "//conditions:default": [
            "-std=c++17",
            "-lstdc++fs",
        ],
    }),
    deps = [
        ":jolly_jumper",
        "@googletest//:gtest_main",
    ],
)

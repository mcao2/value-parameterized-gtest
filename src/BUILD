load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "foo",
    srcs = ["foo.cpp"],
    hdrs = ["foo.h"],
    visibility = ["//test:__pkg__"],
)

cc_binary(
    name = "foo_driver",
    srcs = ["foo_driver.cpp"],
    deps = [
        ":foo",
    ],
)

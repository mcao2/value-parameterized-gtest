cc_test(
    name = "foo-test",
    srcs = glob(["*.cpp", "*.h"]),
    copts = ["-Iexternal/gtest/include", "-Isrc"],
    deps = [
        "@gtest//:gtest",
        "@yaml-cpp//:yaml-cpp",
        "//src:foo",
    ],
    data = ["test_foo.yaml"],
)

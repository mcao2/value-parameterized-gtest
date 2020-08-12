load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "gtest",
    remote = "https://github.com/google/googletest",
    branch = "v1.10.x",
)

http_archive(
    name = "yaml-cpp",
    url = "https://github.com/jbeder/yaml-cpp/archive/yaml-cpp-0.6.3.zip",
    sha256 = "7c0ddc08a99655508ae110ba48726c67e4a10b290c214aed866ce4bbcbe3e84c",
    build_file = "@//external:yaml-cpp.BUILD",
    strip_prefix = "yaml-cpp-yaml-cpp-0.6.3",
)

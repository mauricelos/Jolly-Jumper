workspace(name = "jolly_jumper")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "googletest",
    remote = "https://github.com/google/googletest",
    tag = "release-1.12.1",
)

git_repository(
    name = "benchmark",
    remote = "https://github.com/google/benchmark",
    tag = "v1.7.1",
)

_RULES_BOOST_COMMIT = "88e6c57234692e42ab64822fda172052ad2d528b"

http_archive(
    name = "com_github_nelhage_rules_boost",
    #sha256 = "c1b8b2adc3b4201683cf94dda7eef3fc0f4f4c0ea5caa3ed3feffe07e1fb5b15",
    strip_prefix = "rules_boost-%s" % _RULES_BOOST_COMMIT,
    urls = [
        "https://github.com/nelhage/rules_boost/archive/%s.tar.gz" % _RULES_BOOST_COMMIT,
    ],
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

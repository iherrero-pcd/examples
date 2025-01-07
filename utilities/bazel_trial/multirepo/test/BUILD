cc_test(
    name = "http_free_test",
    size = "small",
    srcs = ["free_test.cpp"],
    deps = [
        "@http_gtest//:gtest",
        "@http_gtest//:gtest_main",
    ],
)

cc_test(
    name = "git_free_test",
    size = "small",
    srcs = ["free_test.cpp"],
    deps = [
        "@git_gtest//:gtest",
	"@git_gtest//:gtest_main",
    ],
)

cc_test(
    name = "local_free_test",
    size = "small",
    srcs = ["free_test.cpp"],
    deps = [
        "@local_gtest//:gtest",
	"@local_gtest//:gtest_main",
    ],
)

cc_test(
    name = "dep_free_test",
    size = "small",
    srcs = ["free_test.cpp"],
    deps = [
        "@dep_gtest//:gtest",
	"@dep_gtest//:gtest_main",
    ],
)

cc_test(
    name = "dep_demo_test",
    size = "small",
    srcs = ["demo_test.cpp"],
    deps = [
        "@dep_gtest//:gtest",
        "@dep_gtest//:gtest_main",
	"//app:greet",
    ],
)


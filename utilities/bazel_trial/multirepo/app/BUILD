cc_library(
    name = "greet",
    srcs = ["greet.cpp"],
    hdrs = ["greet.h"],
    visibility = ["//test:__pkg__"],
)

cc_binary(
    name = "demo",
    srcs = ["main.cpp"],
    deps = [
        ":greet",
        "//lib:time",
    ],
)

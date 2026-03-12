load("@grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@protobuf//bazel:cc_proto_library.bzl", "cc_proto_library")
load("@protobuf//bazel:proto_library.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_binary")

proto_library(
    name = "domus_proto",
    srcs = ["domus.proto"],
)

cc_proto_library(
    name = "domus_cpp_proto",
    deps = [":domus_proto"],
)

cc_grpc_library(
    name = "domus_cpp_grpc",
    srcs = [":domus_proto"],
    grpc_only = True,
    deps = [":domus_cpp_proto"],
)

cc_binary(
    name = "domus_server",
    srcs = ["domus_server.cpp"],
    deps = [
        ":domus_cpp_grpc",
        ":domus_cpp_proto",
        "@grpc//:grpc++",
    ],
)

cc_binary(
    name = "domus_client",
    srcs = ["domus_client.cpp"],
    deps = [
        ":domus_cpp_grpc",
        ":domus_cpp_proto",
        "@grpc//:grpc++",
    ],
)

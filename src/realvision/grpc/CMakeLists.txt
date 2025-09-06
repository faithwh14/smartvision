set(GRPC_CLIENT_MODULE rv_grpc_client)
set(GRPC_SERVER_MODULE rv_grpc_server)

set(GRPC_CLIENT_SRC
)

set(GRPC_SERVER_SRC
)

# ---------------------------------------------------------------

add_library(${GRPC_CLIENT_MODULE} STATIC
    ${GRPC_CLIENT_SRC}
)

target_include_directories(${GRPC_CLIENT_MODULE}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
        ${PROJECT_SOURCE_DIR}/src/realvision
)

target_link_libraries(${GRPC_CLIENT_MODULE}
    PRIVATE
        ect_common
        gRPC::grpc++
        gRPC::grpc++_reflection
        protobuf::libprotobuf
        Threads::Threads
)

# ---------------------------------------------------------------

add_library(${GRPC_SERVER_MODULE} STATIC
    ${GRPC_SERVER_SRC}
)

target_include_directories(${GRPC_SERVER_MODULE}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/common
        ${PROJECT_SOURCE_DIR}/src/realvision
)

target_link_libraries(${GRPC_SERVER_MODULE}
    PRIVATE
        ect_common
        gRPC::grpc++
        gRPC::grpc++_reflection
        protobuf::libprotobuf
        Threads::Threads
)
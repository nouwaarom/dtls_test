cmake_minimum_required(VERSION 3.10)

project(dtls_test)

add_compile_definitions(MBEDTLS_CONFIG_FILE="mbedtls_config.h")

include_directories(inc)
include_directories(dependencies/mbedtls/include)

set(ENABLE_PROGRAMS OFF)
add_subdirectory(dependencies/mbedtls)

link_libraries(mbedtls mbedx509 mbedcrypto)

add_executable(server
        src/main.c
        src/dtls_server.c
        src/certificates.c inc/certificates.h)

add_executable(test_client
        tests/dtls_client.c
        src/certificates.c inc/certificates.h)

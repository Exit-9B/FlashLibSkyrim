cmake_minimum_required(VERSION 3.18)

project(
    FlashLibSkyrim
    LANGUAGES CXX
)

find_package(tsl-ordered-map REQUIRED CONFIG)

include(cmake/sourcelist.cmake)

source_group(
    TREE "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES ${SOURCE_FILES}
)

add_library(
    "${PROJECT_NAME}"
    STATIC
    ${SOURCE_FILES}
    .clang-format
)

add_dependencies("${PROJECT_NAME}" CommonLibSSE::CommonLibSSE)

target_compile_features(
    "${PROJECT_NAME}"
    PUBLIC
        cxx_std_20
)

target_include_directories(
    "${PROJECT_NAME}"
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIR}>"
)

target_link_libraries(
    "${PROJECT_NAME}"
    PUBLIC
        CommonLibSSE::CommonLibSSE
)

target_precompile_headers(
    "${PROJECT_NAME}"
    PRIVATE
        src/PCH/PCH.h
)

install(
    TARGETS "${PROJECT_NAME}"
    EXPORT "${PROJECT_NAME}-targets"
)

install(
    EXPORT "${PROJECT_NAME}-targets"
    NAMESPACE "${PROJECT_NAME}::"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

install(
    DIRECTORY
        "include/RE"
        "include/SWF"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

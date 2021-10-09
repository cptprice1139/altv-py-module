cmake_minimum_required(VERSION 3.8)

project(altv_py_module)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_MODULE_NAME python-module)

file(GLOB_RECURSE PROJECT_SOURCE_FILES "./src/*.h" "./src/*.hpp" "./src/*.cpp")

find_package (Python3 COMPONENTS Development)

include_directories(
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/vendors/cpp-sdk"
        "${PROJECT_SOURCE_DIR}/vendors/pybind11/include"
        "${Python3_INCLUDE_DIRS}"
)

link_libraries("${Python3_LIBRARIES}")

add_library(
        ${PROJECT_MODULE_NAME} SHARED
        ${PROJECT_SOURCE_FILES}
)
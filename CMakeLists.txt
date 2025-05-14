cmake_minimum_required(VERSION 3.31)
project(cpp_stl_study)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(build)

get_filename_component(VCToolsInstallDir "$ENV{VCToolsInstallDir}" ABSOLUTE)

set(STD_IXX_PATH "${VCToolsInstallDir}/modules/std.ixx")

add_subdirectory(001_module)
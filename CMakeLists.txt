cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 14)

project(
  value_param_gtest_eg
  LANGUAGES CXX)

# Default build type is Release
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(
    STATUS
      "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE
      "${default_build_type}"
      CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                               "MinSizeRel" "RelWithDebInfo")
endif()

# Set compile flags
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set compile options
option(BUILD_TEST "if build unit test" OFF)

message("BUILD_TYPE=" ${CMAKE_BUILD_TYPE})
message("BUILD_TEST=" ${BUILD_TEST})

# Build src
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(value_param_gtest_eg ${SOURCES})

target_include_directories(value_param_gtest_eg BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Build test
if(${BUILD_TEST})
  enable_testing()
  add_subdirectory(test)
endif()

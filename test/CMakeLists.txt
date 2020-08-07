# Setups for gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include dependencies
include(../cmake/CodeCoverage.cmake)
find_package(yaml-cpp 0.6 REQUIRED)

set(test_foo_sources
  test_foo_core.cpp
  test_get_bar.cpp
)

set(foo_sources
  ../src/foo.cpp
)

add_executable(test_foo ${test_foo_sources} ${foo_sources})
target_include_directories(test_foo PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_foo yaml-cpp ${GTEST_LIBRARIES})

add_test(test_foo test_foo)

set_tests_properties(test_foo PROPERTIES
  ENVIRONMENT "TEST_FOO_CONFIG_PATH=${CMAKE_SOURCE_DIR}/test/test_foo.yaml;GTEST_OUTPUT=xml:${CMAKE_SOURCE_DIR}/build/reports/gtest_test_foo.xml")

# Make sure you installed gcov and lcov
APPEND_COVERAGE_COMPILER_FLAGS()

SETUP_TARGET_FOR_COVERAGE_LCOV(
  NAME coverage
  EXECUTABLE ctest
  LCOV_ARGS --no-external
  DEPENDENCIES
    test_foo
)

#ifndef TEST_TEST_FOO_CORE_H_
#define TEST_TEST_FOO_CORE_H_

#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include <cassert>
#include <string>
#include <vector>

#include "src/foo.h"

std::vector<YAML::Node> ReadTestCasesFromYaml(const std::string& test_name);

inline std::string SetTestCaseName(
    const testing::TestParamInfo<YAML::Node>& info) {
  return info.param["case_name"].as<std::string>();
}

class FooTest : public testing::TestWithParam<YAML::Node> {
 public:
  void SetUp() override;

 protected:
  YAML::Node config;
  YAML::Node case_params;
  std::string case_assertion;
};

#endif  // TEST_TEST_FOO_CORE_H_

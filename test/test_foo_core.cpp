#include "test_foo_core.h"

const char* TEST_FOO_CONFIG_PATH = std::getenv("TEST_FOO_CONFIG_PATH");

std::unique_ptr<YAML::Node> config_ptr_ =
    std::make_unique<YAML::Node>(YAML::LoadFile(TEST_FOO_CONFIG_PATH));

void FooTest::SetUp() {
  config = GetParam();

  ASSERT_NE(config.size(), 0);

  case_params = config["case_params"];
  case_assertion = config["case_assertion"].as<std::string>();
}

std::vector<YAML::Node> ReadTestCasesFromYaml(const std::string& test_name) {
  assert(config_ptr_ != nullptr);

  YAML::Node config = (*config_ptr_)["Foo"][test_name];

  int num_cases = config.size();
  std::vector<YAML::Node> res_cases;

  std::cout << "[" << test_name << "] Num cases: " << num_cases << std::endl;

  for (int i = 0; i < num_cases; i++) {
    if (config[i]["case_name"])
      std::cout << "Read case " << config[i]["case_name"] << std::endl;
    res_cases.push_back(config[i]);
  }

  assert(res_cases.size() == num_cases);

  return res_cases;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

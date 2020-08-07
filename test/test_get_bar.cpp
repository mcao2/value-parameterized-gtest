#include "test_foo_core.h"

class GetBarTest : public FooTest {};

TEST_P(GetBarTest, GetBar) {
  if (case_assertion.compare("EXPECT_EQ") == 0) {
    auto expected_res = config["case_expected_result"];
    auto res = foo::GetBar();
    ASSERT_EQ(expected_res.size(), res.size());
    for (int i = 0; i < res.size(); i++) {
      EXPECT_EQ(res.at(i).compare(expected_res[i].as<std::string>()), 0);
    }
  } else {
    std::cerr << "Not implemented case_assertion: " << case_assertion
              << std::endl;
  }
}

INSTANTIATE_TEST_SUITE_P(
    GetBarTestInstantiation, GetBarTest,
    ::testing::ValuesIn(ReadTestCasesFromYaml("GetBarTest")), &SetTestCaseName);

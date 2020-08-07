
#include "foo.h"

int main(int argc, char const* argv[]) {
  auto vals = foo::GetBar();

  for (const auto& val : vals) {
    std::cout << val << std::endl;
  }

  return 0;
}

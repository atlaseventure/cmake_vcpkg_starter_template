#include "foo/foo.h"

#include <fmt/format.h>

namespace foo {

std::string foo(int a, int b) {
    int sum = a + b;
    return fmt::format("{} + {} = {}", a, b, sum);
}

}  // namespace foo

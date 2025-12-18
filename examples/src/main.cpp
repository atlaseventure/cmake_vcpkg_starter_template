#include "foo/foo.h"

#include <fmt/core.h>

int main() {
    fmt::println("=== foo Example ===");

    // Example 1: Adding two positive numbers
    std::string result1 = foo::foo(10, 20);
    fmt::println("{}", result1);

    // Example 2: Adding positive and negative
    std::string result2 = foo::foo(50, -25);
    fmt::println("{}", result2);

    return 0;
}

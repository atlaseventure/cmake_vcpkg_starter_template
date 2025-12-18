#include "foo/foo.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("foo adds two positive integers", "[foo]") {
    std::string result = foo::foo(3, 5);
    REQUIRE(result == "3 + 5 = 8");
}

TEST_CASE("foo adds positive and negative integers", "[foo]") {
    std::string result = foo::foo(10, -3);
    REQUIRE(result == "10 + -3 = 7");
}

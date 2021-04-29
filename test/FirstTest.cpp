#include "catch.hpp"
#include "test.hpp"

TEST_CASE("testing the simple implementation", "test") {
    CHECK(add(2, 3) == 5);
}

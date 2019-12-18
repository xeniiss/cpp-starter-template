#include "doctest.h"
#include "test.hpp"

TEST_CASE("testing the simple implementation") {
    CHECK(add(2, 3) == 5);
}
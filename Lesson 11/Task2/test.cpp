#include <catch2/catch_all.hpp>
#include "extended_array.h"
#include <cstring>

TEST_CASE("With range")
{
	SECTION("Valid ranges")
	{
		ExtArray<int> arr{4, 2, 7, 3, -5, 0, -3, 1};
		REQUIRE(arr.mean(1, 4) == 4);
		REQUIRE(arr.mean(1, 2) == 3);
		REQUIRE(arr.mean(3, 4) == 5);
	}
	SECTION("Invalid ranges")
	{
		ExtArray<int> arr{ 4, 2, 7, 3, -5, 0, -3, 1 };
		REQUIRE_THROWS_AS(arr.mean(2, 12), std::invalid_argument);
		REQUIRE_THROWS_AS(arr.mean(0, 4), std::invalid_argument);
		REQUIRE_THROWS_AS(arr.mean(0, 12), std::invalid_argument);
	}
}

#include <catch2/catch_all.hpp>
#include "extended_array.h"

TEST_CASE("If empty")
{
	SECTION("Return null")
	{
		ExtArray<int> arr{};
		REQUIRE(arr.mean() == 0);
		REQUIRE(arr.median() == 0);
		REQUIRE(arr.mode() == std::pair<int, int>{0, 0});
	}
}

TEST_CASE("With range")
{
	SECTION("Valid ranges")
	{
		ExtArray<int> arr{ 4, 2, 7, 3, -5, 0, -3, 1 };
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

TEST_CASE("Check sum")
{
	SECTION("Valid count")
	{
		ExtArray<int> iarr{1, 0, 1, 1};
		ExtArray<bool> barr{1, 0, 0, 1};
		REQUIRE(iarr.checkSum() == 3);
		REQUIRE(barr.checkSum() == 2);
	}
	SECTION("Bad typeid")
	{
		ExtArray<float> arr{ 1, 0, 1, 1 };
		REQUIRE_THROWS_AS(arr.checkSum(), std::bad_typeid);
	}
	SECTION("Bad sum")
	{
		ExtArray<int> arr{ 1, 0, 2, 1 };
		REQUIRE_THROWS_AS(arr.checkSum(), std::logic_error);
	}
}

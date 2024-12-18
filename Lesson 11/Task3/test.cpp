#include <catch2/catch_all.hpp>
#include "extended_array.h"

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

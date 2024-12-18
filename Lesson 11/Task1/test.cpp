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

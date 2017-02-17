#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/algos.hpp"

TEST_CASE("Binary Search - Iterative"){
	std::vector<int> v = {-1, 0, 2, 4};
	int index = algos::search::binarySearch(v, 0);
	REQUIRE(index == 1);
}

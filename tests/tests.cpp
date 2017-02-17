#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/algos.hpp"
using namespace algos;

TEST_CASE("Binary Search - Iterative"){
	std::vector<int> v = {-1, 0, 2, 4};
	int index = search::binarySearch(v, 0);
	REQUIRE(index == 1);
}

TEST_CASE("Binary Search - Recursive"){
	std::vector<int> v = {-1, 0, 2, 4};
	int index = search::binarySearch(v, 0, search::ftype::recursive);
	REQUIRE(index == 1);
}

TEST_CASE("Interpolation Search - Iterative"){
	std::vector<int> v = {-2, 0, 5, 12, 15, 21, 22};
	int index = search::interpolationSearch(v, 15);
	REQUIRE(index == 4);
}

TEST_CASE("Interpolation Search - Recursive"){
	std::vector<int> v = {-2, 0, 5, 12, 15, 21, 22};
	int index = search::interpolationSearch(v, 15, search::ftype::recursive);
	REQUIRE(index == 4);
}

TEST_CASE("K'th Smallest Search"){
	std::vector<int> v = {7, 10, 4, 3, 20, 15};
	int value = search::kthSmallestSearch(v, 3);
	REQUIRE(value == 7);
}

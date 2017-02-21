#include "catch.hpp"
#include "../include/algos.hpp"
using namespace algos;

TEST_CASE("UTILS - Vector To String"){
	std::vector<int> v = {-1, 0, 2, 4};
	REQUIRE("-1, 0, 2, 4" == utils::vectorToString(v));
}

TEST_CASE("SEARCH - Binary Search - Iterative"){
	std::vector<int> v = {-1, 0, 2, 4};
	int index = search::binarySearch(v, 0);
	REQUIRE(index == 1);
}

TEST_CASE("SEARCH - Binary Search - Recursive"){
	std::vector<int> v = {-1, 0, 2, 4};
	int index = search::binarySearch(v, 0, search::functype::recursive);
	REQUIRE(index == 1);
}

TEST_CASE("SEARCH - Interpolation Search - Iterative"){
	std::vector<int> v = {-2, 0, 5, 12, 15, 21, 22};
	int index = search::interpolationSearch(v, 15);
	REQUIRE(index == 4);
}

TEST_CASE("SEARCH - Interpolation Search - Recursive"){
	std::vector<int> v = {-2, 0, 5, 12, 15, 21, 22};
	int index = search::interpolationSearch(v, 15, search::functype::recursive);
	REQUIRE(index == 4);
}

TEST_CASE("SEARCH - K'th Smallest"){
	std::vector<int> v = {7, 10, 4, 3, 20, 15};
	int value = search::kthSmallest(v, 3);
	REQUIRE(value == 7);
}

TEST_CASE("SORT - Bubble Sort"){
	std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
	sort::bubbleSort(v);
	std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
	REQUIRE(v == vComp);
}

TEST_CASE("SORT - Modified Bubble Sort"){
	std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
	sort::modifiedBubbleSort(v);
	std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
	REQUIRE(v == vComp);
}

TEST_CASE("SORT - Selection Sort"){
	std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
	sort::selectionSort(v);
	std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
	REQUIRE(v == vComp);
}

TEST_CASE("SORT - Insertion Sort"){
	std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
	sort::insertionSort(v);
	std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
	REQUIRE(v == vComp);
}

TEST_CASE("DATA STRUCTURES - Max Heap"){
	/*
	 * 			20	
	 * 		2		1
	 * 	3	 10	      9 	-1
	 * 6 
	 */
	std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
	ds::MaxHeap mh(v);
	REQUIRE(mh.size() == 8);

	SECTION("check isLeaf function"){
		bool isLeaf;
		for(int i = 0; i < mh.size(); i++){
			isLeaf = mh.isLeaf(i);
			if(i >= 4 && i <= 7){
				REQUIRE(isLeaf == true);
			}else{
				REQUIRE(isLeaf == false);
			}
		}
	}
	
}

TEST_CASE("SORT - Max Heap Sort"){
	std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
	sort::heapSort(v);
	std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
	REQUIRE(v == vComp);
}

TEST_CASE("SORT - Merge Sort"){
	std::vector<int> v2 = {2, 3, 1, 6, 10, 9, 20};
	sort::mergeSort(v2);
	std::vector<int> v2Comp = {1, 2, 3, 6, 9, 10, 20};
	REQUIRE(v2 == v2Comp);
	std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
	sort::mergeSort(v);
	std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
	REQUIRE(v == vComp);
}

TEST_CASE("SORT - Quick Sort"){
	std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
	sort::quickSort(v);
	std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
	REQUIRE(v == vComp);
}


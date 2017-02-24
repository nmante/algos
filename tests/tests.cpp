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

TEST_CASE("SORT - Quick Sort Recursive"){
	SECTION("Array of 8 numbers with a negative number"){
		std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
		sort::quickSort(v);
		std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
		REQUIRE(v == vComp);
	}
	SECTION("Array of 8 positive numbers"){
		std::vector<int> v = {2, 3, 1, 6, 10, 9, 4, 20};
		sort::quickSort(v);
		std::vector<int> vComp = {1, 2, 3, 4, 6, 9, 10, 20};
		REQUIRE(v == vComp);
	}
	SECTION("Array of 1 number"){
		std::vector<int> v = {2};
		sort::quickSort(v);
		std::vector<int> vComp = {2};
		REQUIRE(v == vComp);
	}
	SECTION("Array of 8 negative numbers"){
		std::vector<int> v = {-2, -3, -30, -7, -10, -9, -1, -20};
		sort::quickSort(v);
		std::vector<int> vComp = {-30, -20, -10, -9, -7, -3, -2, -1};
		REQUIRE(v == vComp);
	}
	SECTION("Array of sorted numbers"){
		std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		sort::quickSort(v);
		std::vector<int> vComp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		REQUIRE(v == vComp);
	}
	SECTION("Huge array of unsorted integers"){
		std::vector<int> v = {20, 30, -1, 50, 100, 2, 5, 6, 59, 210, 54, 55, 67, 99, 1002, 40, 42, 31, 65, 77, -20, -52, -73, 301, 66, 32, -57};
		sort::quickSort(v);
		std::vector<int> vComp = {-73, -57, -52, -20, -1, 2, 5, 6, 20, 30, 31, 32, 40, 42, 50, 54, 55, 59, 65, 66, 67, 77, 99, 100, 210, 301, 1002};
		REQUIRE(v == vComp);
	}
}

TEST_CASE("SORT - Quick Sort Iterative"){
	SECTION("Array of 8 numbers with negative number"){
		std::vector<int> v = {2, 3, 1, 6, 10, 9, -1, 20};
		sort::quickSortIterative(v);
		std::vector<int> vComp = {-1, 1, 2, 3, 6, 9, 10, 20};
		REQUIRE(v == vComp);
	}
	SECTION("Array of 8 positive numbers"){
		std::vector<int> v = {2, 3, 1, 6, 10, 9, 4, 20};
		sort::quickSortIterative(v);
		std::vector<int> vComp = {1, 2, 3, 4, 6, 9, 10, 20};
		REQUIRE(v == vComp);
	}
	SECTION("Array of 1 number"){
		std::vector<int> v = {2};
		sort::quickSortIterative(v);
		std::vector<int> vComp = {2};
		REQUIRE(v == vComp);
	}
	SECTION("Array of 8 negative numbers"){
		std::vector<int> v = {-2, -3, -30, -7, -10, -9, -1, -20};
		sort::quickSortIterative(v);
		std::vector<int> vComp = {-30, -20, -10, -9, -7, -3, -2, -1};
		REQUIRE(v == vComp);
	}
	SECTION("Huge array of unsorted integers"){
		std::vector<int> v = {20, 30, -1, 50, 100, 2, 5, 6, 59, 210, 54, 55, 67, 99, 1002, 40, 42, 31, 65, 77, -20, -52, -73, 301, 66, 32, -57};
		sort::quickSortIterative(v);
		std::vector<int> vComp = {-73, -57, -52, -20, -1, 2, 5, 6, 20, 30, 31, 32, 40, 42, 50, 54, 55, 59, 65, 66, 67, 77, 99, 100, 210, 301, 1002};
		REQUIRE(v == vComp);
	}

}

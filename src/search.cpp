#include "../include/search.hpp"

namespace algos {
namespace search {

int binarySearchIterative(std::vector<int> arr, int target){
	int start = 0, end = (int)arr.size() - 1;
	
	while (end > start) {
		int mid = (start + end) / 2;
		if (target == arr[mid]){
			return mid;
		}else if (target > arr[mid]) {
			start = mid + 1;
		}else {
			end = mid - 1;
		}
	}
	return -1;
}

int binarySearchRecursiveHelper(std::vector<int> arr, int target, int start, int end){
	int mid = (start + end) / 2; 
	if (target == arr[mid]) {
		return mid;
	}
	return (target > arr[mid]) 
		? binarySearchRecursiveHelper(arr, target, mid + 1, end) 
		: binarySearchRecursiveHelper(arr, target, start, mid - 1);
}

int binarySearchRecursive(std::vector<int> arr, int target){
	return binarySearchRecursiveHelper(arr, target, 0, arr.size() - 1);
}


int binarySearch(std::vector<int> arr, int target, ftype type){
	int result = - 1;
	switch (type) {
		case ftype::recursive:
			result = binarySearchRecursive(arr, target);
			break;
		case ftype::iterative:
			result = binarySearchIterative(arr, target);
			break;
		default:
			result = binarySearchIterative(arr, target);
			break;
	}
	
	return result;
}

}
}


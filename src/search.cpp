#include "../include/search.hpp"
#include <limits.h>

namespace algos {
namespace search {

/*
 * BINARY SEARCH
 */

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
	if (start > end) {
		return -1;
	}

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


int binarySearch(std::vector<int> arr, int target, functype type){
	int result = - 1;
	switch (type) {
		case functype::recursive:
			result = binarySearchRecursive(arr, target);
			break;
		case functype::iterative:
			result = binarySearchIterative(arr, target);
			break;
		default:
			result = binarySearchIterative(arr, target);
			break;
	}
	
	return result;
}

/*
 * INTERPOLATION SEARCH
 */

int interpolationSearchIterative(std::vector<int> arr, int target){
	int start = 0, end = arr.size() - 1;
	while (end > start && arr[start] < target && arr[end] > target) {
		int pos = start + (target - arr[start]) * (end - start)/(arr[end] - arr[start]);
		if (target == arr[pos]){
			return pos;
		}else if (target > arr[pos]){
			start = pos + 1;
		}else {
			end = pos - 1;
		}
	}
	return -1;
}

int interpolationSearchRecursiveHelper(std::vector<int> arr, int target, int start, int end){
	if (start > end) {
		return -1;
	}

	int pos = start + (target - arr[start]) * (end - start)/(arr[end] - arr[start]);

	if (target == arr[pos]){
		return pos;
	}

	return (target > arr[pos]) 
		? interpolationSearchRecursiveHelper(arr, target, pos + 1, end)
		: interpolationSearchRecursiveHelper(arr, target, start, pos - 1);
}

int interpolationSearchRecursive(std::vector<int> arr, int target){
	return interpolationSearchRecursiveHelper(arr, target, 0, arr.size() - 1);
}

int interpolationSearch(std::vector<int> arr, int target, functype type){
	/*
	 * Linear Interpolation formula
	 * y - y0   y1 - y0
	 * ------ = -------
	 * x - x0 = x1 - x0
	 *
	 * y = position or index we're searching for
	 * x = value or target we're provided
	 * x0 = value at index start
	 * x1 = value at index end
	 * y1 = position of end
	 */
	int result = -1;
	switch (type) {
		case functype::recursive:
			result = interpolationSearchRecursive(arr, target);
		case functype::iterative:
			result = interpolationSearchIterative(arr, target);
		default:
			break;
	}
	return result;
}

/*
 * K'th SMALLEST/LARGEST element in an unsorted array
 */

int kthSmallest(std::vector<int> arr, int k){
	/*
	 * Options
	 * 	- brute force in O(n^2)
	 * 	- sort 'arr' pluck kth largest in NlogN time
	 * 	- MaxHeap and pluck kth largest in n + klogn time 
	 */
	if (k > (int)arr.size()){
		return -1;
	}	
	int value = INT_MIN;

	// Brute force
	for(int i = 0; i < (int)arr.size(); i++){
		int numLessThan = 0;
		for(int j = 0; j < (int)arr.size(); j++){
			if (i == j){
				continue;
			}
			if(arr[i] > arr[j]){
				numLessThan++;
			}
		}
		if (numLessThan == (k - 1)){
			return arr[i];
		}
	}

	return value;
}

int kthLargest(std::vector<int> arr, int k){
	/*
	 * Options
	 * 	- brute force in O(n^2)
	 * 	- sort 'arr' pluck kth largest in NlogN time
	 * 	- MaxHeap and pluck kth largest in n + klogn time 
	 */
	int value = INT_MIN; 

	return value;
}

}
}


#include "../include/sort.hpp"
#include <iostream>
#include "../include/maxheap.hpp"
#include "../include/utils.hpp"

namespace algos {
namespace sort {

void bubbleSort(std::vector<int> &arr){
	/*
	 * Iterate over entire array, and compare 
	 */
	for(int i = 0; i < (int)arr.size(); i++){
		for(int j = 0; j < (int)arr.size() - 1; j++){
			if(arr[j] > arr[j+1]){
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void modifiedBubbleSort(std::vector<int> &arr){
	for(int i = 0; i < (int)arr.size(); i++){
		bool exchangeMade = false;
		for(int j = 0; j < (int)arr.size() - 1; j++){
			if(arr[j] > arr[j+1]){
				exchangeMade = true;
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
		// If we didn't swap at all, then nothing is out of order
		// Means list is sorted and we can exit
		if(!exchangeMade){
			break;
		}
	}
}

void selectionSort(std::vector<int> &arr){
	/*
	 * Selection Sort
	 * Think of the array as two portions
	 * Sorted and unsorted part
	 * Iterate through the array
	 * Select the minimum element from the unsorted part
	 * Append it to the sorted part 
	 */
	for(int i = 0; i < (int)arr.size(); i++){
		int minIndex = i;
		for(int j = i; j < (int)arr.size(); j++){
			// Select the minimum value from the unsorted portion 
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		// Append the minimum value to the end of the sorted portion
		int tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}

void insertionSort(std::vector<int> &arr){
	/*
	 * Insertion Sort
	 * Think of array as two portions
	 * Partially sorted, and unsorted where partially sorted is the "left" part
	 * and unsorted is "right" part of the array
	 * Choose first "element" from unsorted portion, and compare
	 * it to the left parts
	 * Any item greater than the "element" should be shifted right
	 */ 

	for(int i = 1; i < (int)arr.size(); i++){
		// Choose element and store value
		int tmp = arr[i];
		for(int j = i - 1; j >= 0; j--){
			if(arr[j] > tmp){
				// Move larger values to the right part of the array 
				arr[j+1] = arr[j]; 
				arr[j] = tmp;
			}else{
				// No more values are larger than the current value
				break;
			}
		}
	}
}

/*
 * Heap Sort - O(n*log(n)), unstable sort
 */
void heapSort(std::vector<int> &arr){
	using namespace algos;
	ds::MaxHeap mh(arr);
	auto arr2 = mh.getArray();

	std::vector<int> sortedList;
	while (mh.size() > 0){
		sortedList.insert(sortedList.begin(), mh.removeMax());
	}
	arr = sortedList;

}

/*
 * Merge Sort - O(n*log(n)), stable sort
 */
void merge(std::vector<int> &arr, int begin, int mid, int end){
	// Create two temporary sub arrays
	//std::vector<int> left = std::vector<int>(arr.begin(), arr.begin() + mid);
	//std::vector<int> right = std::vector<int>(arr.begin() + mid, arr.begin() + end);
	std::vector<int> left, right;

	for(int k = begin; k <= mid; k++){
		left.push_back(arr[k]);
	}	
	for(int k = mid + 1; k <= end; k++){
		right.push_back(arr[k]);
	}	
	
	int i = 0, j = 0, k = begin;

	// Now iterate through both sub arrays
	// Compare the beginning of each sub array, and choose the beginning
	// that 'wins' to put back into the original array
	while(i < (int)left.size() && j < (int)right.size()){
		// insert 'winner' into original array
		if(left[i] < right[j]){
			arr[k++] = left[i++];
		}else{
			arr[k++] = right[j++];
		}
	}

	// Copy any extra elements from the sub arrays over to the original
	while (i < (int)left.size()){
		arr[k++] = left[i++];
	}
	while (j < (int)right.size()){
		arr[k++] = right[j++];
	}
	
}

void mergeSortHelper(std::vector<int> &arr, int begin, int end){
	// Recursively divide the array into two parts
	// Merge once we have 0 or 1 elements
	if (begin < end){
		int mid = (begin + end) / 2;
		mergeSortHelper(arr, begin, mid);
		mergeSortHelper(arr, mid + 1, end);
		merge(arr, begin, mid, end);
	}
}

void mergeSort(std::vector<int> &arr){
	// Keep API simple, caller only needs to pass array
	// Now pass along the array and it's beginning/end
	mergeSortHelper(arr, 0, (int)arr.size() - 1);
}

/*
 * Quick Sort
 */

int partition(std::vector<int> &arr, int low, int high){
	// from low position to high position, 
	int left = low, pivot = low;
	int pivotItem = arr[pivot];
	int right = high;

	while (left < right) {
		while( arr[left] <= pivotItem ) { left++; } 
		while( arr[right] > pivotItem ) { right--; } 
		if (left < right)
			std::swap(arr[left], arr[right]);

	}

	arr[low] = arr[right];
	arr[right] = pivotItem;
	return right;
}

void quickSortHelper(std::vector<int> &arr, int low, int high){
	if (high > low) {
		// Partition
		int pivot = partition(arr, low, high);
		
		// Sort left half
		std::cout << "high left: " << pivot - 1 << std::endl;
		quickSortHelper(arr, low, pivot - 1);
		
		// sort right half
		std::cout << "low right: " << pivot + 1 << std::endl;
		quickSortHelper(arr, pivot + 1, high);
		
	}
}

void quickSortIterative(std::vector<int> &arr){
	int low = 0;
	int high = arr.size() - 1;

	int highLeft = high; // End of the left sub array
	int lowRight = low; // Beginning of the right sub array	
	std::cout << "HELLO ITER" << std::endl;
	
	while (low < highLeft || lowRight < high){
		// Partition left sub array until it's beginning and end cross
		std::cout << "high left: " << highLeft - 1 << std::endl;
		std::cout << "high left val: " << arr[highLeft - 1] << std::endl;
		if (low < highLeft)
			highLeft = partition(arr, low, highLeft - 1);

		// Partition left sub array until it's beginning and end cross
		std::cout << "low right: " << lowRight + 1<< std::endl;
		std::cout << "low right val: " << arr[lowRight + 1] << std::endl;
		if (lowRight < high)
			lowRight = partition(arr, lowRight + 1, high);
	}
}

void quickSort(std::vector<int> &arr){
	std::cout << "Hello RECURSE" << std::endl;
	quickSortHelper(arr, 0, arr.size() - 1);
}

}
}

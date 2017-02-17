#include "../include/sort.hpp"

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

void heapSort(std::vector<int> &arr){
	
}

void mergeSort(std::vector<int> &arr){

}

void quickSort(std::vector<int &arr){

}


}
}

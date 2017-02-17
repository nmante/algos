#include "../include/sort.hpp"

namespace algos {
namespace sort {

void bubbleSort(std::vector<int> &arr){
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
}
}

#include "../../include/heap/minheap.hpp"
#include "../../include/utils.hpp"
#include <iostream>

namespace algos {
namespace ds {

bool MinHeap::isLeaf(int nodeIndex) const {
	int leftChildIndex = this->getLeftChildIndex(nodeIndex);
	int rightChildIndex = this->getRightChildIndex(nodeIndex);
	return leftChildIndex == -1 && rightChildIndex == -1;
}

bool MinHeap::isValid(int nodeIndex) const {
	return nodeIndex >= 0 && nodeIndex < this->size();
}

int MinHeap::getParentIndex(int nodeIndex) const {
	// Root case & error case
	if(nodeIndex <= 0){
		return -1;
	}

	int index;	
	if(nodeIndex % 2){
		// Left children indices odd 
		index = (nodeIndex - 1)/2;
	}else{
		// Right children indices even
		index = (nodeIndex - 2)/2;
	}
	
	return index < this->size() ? index : -1;
}

int MinHeap::getRightChildIndex(int nodeIndex) const {
	if(nodeIndex < 0){
		return -1;
	}
	int index = 2*nodeIndex + 2;
	
	// Return -1 if right child index out of bounds
	return index < this->size() ? index : -1;
}

int MinHeap::getLeftChildIndex(int nodeIndex) const {
	if(nodeIndex < 0){
		return -1;
	}
	int index = 2*nodeIndex + 1;
	return index < this->size() ? index : -1;
}

int MinHeap::getMin() const {
	if(this->isEmpty()){
		return INT_MAX;
	}
	return this->getArray()[0];
}
int MinHeap::removeMin() {
	if(this->isEmpty()){
		return INT_MAX;
	}
	int min = this->getMin();
	this->array[0] = this->array[this->size() - 1];
	this->array.pop_back();
	this->heapDown(0);
	return min;
}

void MinHeap::buildMinHeap(){
	for(int i = this->size() - 1; i >= 0; i--){
		this->heapDown(i);
	}
	
}

void MinHeap::heapDown(int nodeIndex){
	// Only heapify non child nodes
	while(!this->isLeaf(nodeIndex)){

		// Find the smallest child
		int minIndex = this->getLeftChildIndex(nodeIndex);
		if(this->isValid(minIndex) 
			&& this->array[minIndex] > this->array[minIndex + 1]){
			minIndex++;
		}

		if(this->array[nodeIndex] <= this->array[minIndex]){
			return;
		}

		std::swap(this->array[nodeIndex], 
				this->array[minIndex]);

		nodeIndex = minIndex;

	}
}

}
}

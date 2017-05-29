#include "../../include/heap/maxheap.hpp"
#include "../../include/utils.hpp"
#include <limits.h>
#include <iostream>

namespace algos {
namespace ds {

bool MaxHeap::isLeaf(int nodeIndex) const {

	// Checking for a node outside array bounds
	if (nodeIndex >= (int)this->array.size() ||
			nodeIndex < 0){
		return false;
	}

	// We are a leaf, if our calculated child indices are greater
	// than the size of the array
	int leftInd = 2*nodeIndex + 1;
	int rightInd = 2*nodeIndex + 2;
	
	// If we don't have a left and right child, we are a leaf
	if(leftInd >= this->size() && rightInd >= this->size()){
		return true;
	}

	return false;
}

int MaxHeap::getParentIndex(int nodeIndex) const{
	// for node i, it's children are
	// left = 2*i + 1, and right = 2*i - 1
	// That means the parent is the inverse
	// also, left children are odd indices
	// so if the index given is odd, use the left formula
	// p_left = (nodeIndex - 1)/2
	// p_right = (nodeIndex - 2)/2
	
	if (nodeIndex == 0) {
		// It's the root, it has no parent
		return -1;
	}
	
	if (nodeIndex % 2 == 0){
		// It's a right child
		return (nodeIndex - 2)/2;
	}else{
		// It's a left child
		return (nodeIndex - 1)/2;
	}

	return -1;
}

int MaxHeap::getRightChildIndex(int nodeIndex) const{
	// Leaf nodes can't have children
	if(this->isLeaf(nodeIndex)){
		return -1;
	}

	int index = 2*nodeIndex + 2;
	return (index >= this->size()) ? -1 : index;
}

int MaxHeap::getLeftChildIndex(int nodeIndex) const{
	// Leaf nodes can't have children
	if(this->isLeaf(nodeIndex)){
		return -1;
	}

	int index = 2*nodeIndex + 1;
	return (index >= this->size()) ? -1 : index;
}


bool MaxHeap::isEmpty() const { 
	return array.size() == 0; 
}

int MaxHeap::removeMax(){
	if(this->isEmpty()){
		return INT_MIN;
	}

	// Get the max value
	int max = this->array[0];

	// Now update the array
	int last = this->array.back();
	this->array.pop_back();
	this->array[0] = last;  

	// Now update the heap
	this->heapDown(0);

	return max;

}

int MaxHeap::getMax(){
	if (this->isEmpty()){
		return INT_MIN;
	}
	return this->array[0];

}

void MaxHeap::buildMaxHeap(){
	// Create a new array
	// Iterate through our underlying array
	// Take element
	// As we iterate check to see if child is bigger
	// if it is, swap child with parent 
	for(int i = this->size() - 1; i >= 0; i--){
		this->heapDown(i);
	}
}

void MaxHeap::heapDown(int nodeIndex){
	// Only do heapify on a non child node
	while (!isLeaf(nodeIndex)) {
		// Find the bigger child node
		int maxChildIndex = this->getLeftChildIndex(nodeIndex);
		if ( maxChildIndex < this->size() - 1 
		&& this->array[maxChildIndex] < this->array[maxChildIndex + 1]){ 
			maxChildIndex++;
		}

		// Child smaller, so we're done
		if(this->array[nodeIndex] >= this->array[maxChildIndex]){
			return;
		}
		// If the child is bigger, swap with parent
		std::swap(this->array[nodeIndex],
			this->array[maxChildIndex]);

		nodeIndex = maxChildIndex;
	}

}

}
}



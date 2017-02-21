#include "../include/maxheap.hpp"
#include <limits.h>

namespace algos {
namespace ds {

bool MaxHeap::isLeaf(int nodeIndex) const {

	// Checking for a node outside array bounds
	if (nodeIndex >= (int) this->array.size() ||
			nodeIndex < 0){
		return false;
	}

	// If we are the last right or left child, we're a leaf 
	if (((int)this->array.size() - 1) == nodeIndex ||
		(int)this->array.size() - 2 == nodeIndex){
		return true;
	}

	return false;
}

int MaxHeap::getParentIndex(int nodeIndex) {
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

int MaxHeap::getRightChildIndex(int nodeIndex) {

	// Leaf nodes can't have children
	if (this->isLeaf(nodeIndex)) {
		return -1;
	}

	// Must have two items in array after 'nodeIndex' to have a right child
	if (nodeIndex <= ((int)this->array.size() - 3)){
		return (2*nodeIndex + 2);
	}

	return -1;
}

int MaxHeap::getLeftChildIndex(int nodeIndex) {
	// Leaf nodes can't have children
	if(this->isLeaf(nodeIndex)){
		return -1;
	}

	if (nodeIndex <= ((int)this->array.size() - 3)){
		return (2*nodeIndex + 1);
	}

	return -1;
}


bool MaxHeap::isEmpty() const { 
	return (array.size() == 0) ? true : false; 
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
	this->MoveNode(0);

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
	for(int i = (int)this->array.size() - 1; i >= 0; i--){
		this->MoveNode(i);
	}
}

void MaxHeap::MoveNode(int nodeIndex){
	// Only do heapify on a non child node
	while (!isLeaf(nodeIndex)) {
		// Find the bigger child node
		int maxChildIndex = this->getLeftChildIndex(nodeIndex);
		if ( (maxChildIndex < this->getNumNodes() - 1) 
		&& this->array[maxChildIndex] < this->array[maxChildIndex + 1]){ 
			maxChildIndex++;
		}

		// Child bigger, so we're done
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



#ifndef __MINHEAP_HPP__
#define __MINHEAP_HPP__
#include "heap.hpp"

namespace algos {
namespace ds {

template <class V, class comp>
class MinHeap : Heap<V, comp>{
private:
	void heapDown(int nodeIndex);
public:
	void buildHeap();

};

template <class V, class comp>
void MinHeap<V, comp>::buildHeap(){
	// Create a new array
	// Iterate through our underlying array
	// Take element
	// As we iterate check to see if child is bigger
	// if it is, swap child with parent 
	for(int i = this->size() - 1; i >= 0; i--){
		this->heapDown(i);
	}
}

template <class V, class comp>
void MinHeap<V, comp>::heapDown(int nodeIndex){

	// Only heapify non child nodes
	while(!this->isLeaf(nodeIndex)){

		// Find the smallest child
		int minIndex = this->getLeftChildIndex(nodeIndex);
		bool leftChildSmaller = comp()(this->array[minIndex],
				this->array[minIndex + 1]); 
		if(this->isValid(minIndex) 
			&& !leftChildSmaller){
			minIndex++;
		}

		// If the child is bigger we're done 
		if(!comp()(this->array[minIndex], this->array[nodeIndex])){
			return;
		}

		std::swap(this->array[nodeIndex], 
				this->array[minIndex]);

		nodeIndex = minIndex;
	}
}

}
}

#endif // __MINHEAP_HPP__

#ifndef __MAXHEAP_HPP__
#define __MAXHEAP_HPP__
#include "heap.hpp"
#include <vector>

namespace algos {
namespace ds {

template <class V, class comp = Comparator<V> >
class MaxHeap : public Heap<V, comp>{
private:
	void heapDown(int nodeIndex);
public:
	void buildHeap();
	MaxHeap(std::vector<V> arr)
		: Heap<V, comp>(arr)
	{
	}
};	

template <class V, class comp>
void MaxHeap<V, comp>::buildHeap(){
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
void MaxHeap<V, comp>::heapDown(int nodeIndex){
	// Only do heapify on a non child node
	while (!this->isLeaf(nodeIndex)) {
		// Find the bigger child node
		int maxChildIndex = this->getLeftChildIndex(nodeIndex);
		bool leftChildSmaller = comp()(this->array[maxChildIndex], 
			this->array[maxChildIndex + 1]);

		if ( maxChildIndex < this->size() - 1 
			&& leftChildSmaller){ 
			maxChildIndex++;
		}

		// Child smaller, so we're done
		bool childLessThanParent = comp()(this->array[maxChildIndex],
			       this->array[nodeIndex]);	

		if(childLessThanParent){
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
#endif // __MAXHEAP_HPP__

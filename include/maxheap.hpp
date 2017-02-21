#ifndef __MAXHEAP_HPP__
#define __MAXHEAP_HPP__
#include <vector>

namespace algos {
namespace ds {

class MaxHeap {
private:
	std::vector<int> array;
	void MoveNode(int nodeIndex);
public:
	MaxHeap(){}
	MaxHeap(std::vector<int> arr) : array(arr){ 
		this->buildMaxHeap();
	}
	MaxHeap(const MaxHeap &m) : array(m.array){
		this->buildMaxHeap();
	}
	/*
	MaxHeap& operator=(const MaxHeap &src){
		this->array = src.array;
		this->buildMaxHeap();
		return ;
	}*/

	~MaxHeap(){}

	bool isLeaf(int nodeIndex) const;
	int getParentIndex(int nodeIndex);
	int getRightChildIndex(int nodeIndex);
	int getLeftChildIndex(int nodeIndex);

	bool isEmpty() const;
	std::vector<int> getArray() const { return array; }
	int getNumNodes() const { return (int)this->array.size(); }
	
	int getMax();
	int removeMax();
	void buildMaxHeap();
};	

}
}
#endif // __MAXHEAP_HPP__

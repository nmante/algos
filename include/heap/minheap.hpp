#ifndef __MINHEAP_HPP__
#define __MINHEAP_HPP__
#include <vector>

namespace algos {
namespace ds {

class MinHeap {
private:
	std::vector<int> array;
	void buildMinHeap();
	void heapDown(int nodeIndex);

public:
	MinHeap(){}
	MinHeap(std::vector<int> arr) : array(arr) {
		this->buildMinHeap();
	}
	MinHeap(const MinHeap &m) : array(m.array) {
		this->buildMinHeap();
	}

	~MinHeap(){}

	bool isEmpty() const { return this->size() == 0; }
	std::vector<int> getArray() const { return array; }
	int size() const { return (int)this->array.size(); }

	bool isLeaf(int nodeIndex) const;
	bool isValid(int nodeIndex) const;
	int getParentIndex(int nodeIndex) const;
	int getRightChildIndex(int nodeIndex) const;
	int getLeftChildIndex(int nodeIndex) const;

	int getMin() const;
	int removeMin();

};

}
}

#endif // __MINHEAP_HPP__

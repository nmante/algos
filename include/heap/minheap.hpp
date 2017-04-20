#ifndef __MINHEAP_HPP__
#define __MINHEAP_HPP__
#include <vector>

class MinHeap {
private:
	std::vector<int> array;

public:
	MinHeap(){}
	MinHeap(std::vector<int> arr) : array(arr) {}
	MinHeap(const MinHeap &m) : array(m.array) {}


	bool isEmpty() const;
	std::vector<int> getArray() const { return array; }
	int size() const { return (int)this->array.size(); }

	
	int getMin();
	int removeMin();
	void buildMinHeap();

};

#endif // __MINHEAP_HPP__

#ifndef __HEAP_HPP__
#define __HEAP_HPP__
#include <vector>
#include <iostream>

namespace algos {
namespace ds {

template <class V>
class Comparator {
public:
	bool operator() (V &a, V &b) {
		return a < b;
	}
};

template <class V, class Comp = Comparator<V>>
class Heap {

protected:
	std::vector<V> array;
	virtual void buildHeap() = 0;

private:
	virtual void heapDown(int nodeIndex) = 0;
	
public:
	Heap(){}
	Heap(std::vector<V> arr) 
		: array(arr)
	{}

	Heap(const Heap &m) 
		: array(m.array)
	{}

	~Heap(){}

	bool isEmpty() const;
	std::vector<V> getArray() const { return array; }
	int size() const { return (int)this->array.size(); }

	bool isLeaf(int nodeIndex) const;
	int getParentIndex(int nodeIndex) const;
	int getRightChildIndex(int nodeIndex) const;
	int getLeftChildIndex(int nodeIndex) const;

	void insert(V value);
	
	V getTop();
	V removeTop();
	
};	



template <class V, class comp>
bool Heap<V, comp>::isLeaf(int nodeIndex) const {

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

template <class V, class comp>
int Heap<V, comp>::getParentIndex(int nodeIndex) const{
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

template <class V, class comp>
int Heap<V, comp>::getRightChildIndex(int nodeIndex) const{
	// Leaf nodes can't have children
	if(this->isLeaf(nodeIndex)){
		return -1;
	}

	int index = 2*nodeIndex + 2;
	return (index >= this->size()) ? -1 : index;
}

template <class V, class comp>
int Heap<V, comp>::getLeftChildIndex(int nodeIndex) const{
	// Leaf nodes can't have children
	if(this->isLeaf(nodeIndex)){
		return -1;
	}

	int index = 2*nodeIndex + 1;
	return (index >= this->size()) ? -1 : index;
}


template <class V, class comp>
bool Heap<V, comp>::isEmpty() const { 
	return array.size() == 0; 
}



template <class V, class comp>
V Heap<V, comp>::removeTop(){
	if(this->isEmpty()){
		throw std::length_error("List is empty");
	}
	V top = this->array[0];
	if(this->size() == 1){
		this->array.pop_back();
		return top;
	}

	V last = this->array.back();
	this->array.pop_back();
	this->array[0] = last;

	// Update heap
	this->heapDown(0);
	return top;
}

template <class V, class comp>
V Heap<V, comp>::getTop() {
	if(this->isEmpty()){
		throw std::length_error("List is empty");
	}
	return this->array[0];
}

template <class V, class comp>
void Heap<V, comp>::insert(V value) {
	this->array.push_back(value);
	this->heapDown(0);
}

}
}
#endif // __HEAP_HPP__

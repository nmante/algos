#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__
#include <iostream>

namespace algos {
namespace ds {

template <class T>
class LinkedList {
	// Internal Node Class
	template <class Type>
	class Node {
		Type data;
	public:
		Node *next { nullptr };
		Node(Type data)
			: data(data)
		{}
		Node(Type data, Node<Type> *next) 
			: data(data)
			, next(next)
		{}
		~Node(){
			next = nullptr;
		}
	};

	// Linked List Definition
	Node<T> *head { nullptr };

	Node<T> *findNode(T data){
		auto *tmp = this->head;
		while(tmp){
			if(tmp->data == data){
				return tmp;
			}
			tmp = tmp->next;
		}
		return nullptr;
	}

	Node<T> *getLast(){
		auto *tmp = this->head;
		while(tmp && tmp->next){
			tmp = tmp->next;
		}
		return tmp;
	}

public:
	LinkedList();
	~LinkedList();

	int size() const {
		int sz = 0;
		auto *tmp = this->head;
		while(tmp){
			sz++;
		}
		return sz;
	}

	bool empty() const {
		return this->head == nullptr ? true : false;
	}

	void prepend(T data){
		if(this->head == nullptr){
			head = new Node<T>(data);
			return;
		}
		auto *tmp = new Node<T>(data);
		tmp->next = this->head;
		this->head = tmp;
	}

	void append(T data){
		// Traverse to end
		auto *last = this->getLast();
		auto *newNode = new Node<T>(data);
		if(last == nullptr){
			this->head = newNode; 
		}else{
			last->next = newNode; 
		}
	}

	void insertAfter(T temp, T newData){
		auto *node = this->findNode(temp);
		if(node == nullptr){
			return;
		}

		auto *nextTemp = node->next;
		node->next = new Node<T>(newData, nextTemp);
	}

	void removeHead(){
		auto *tmp = this->head;
		this->head = tmp ? tmp->next : nullptr;
		delete tmp;
		tmp = nullptr;
	}

	void removeTail(){
		if(this->head == nullptr){
			return;
		}

		// Keep track of previous and curr ptr
		auto *curr = this->head;
		Node<T> *prev = nullptr;
		while(curr){
			if(curr->next == nullptr){
				if(prev != nullptr){
					prev->next = nullptr;
				}else{ 
					this->head = nullptr; 
				}
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}

	// Remove node with the value 'toRemove'
	void removeNode(T toRemove){
		auto *curr = this->head;
		Node<T> *prev = nullptr;
		while(curr){
			if(curr->data == toRemove){
				if(prev != nullptr){
					prev->next = curr->next;
				}else{
					this->head = nullptr;
				}
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}
};

}
}
#endif // __LINKEDLIST_HPP__

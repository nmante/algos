#ifndef __NODE_HPP__
#define __NODE_HPP__
#include <memory> // unique_ptr

namespace algos {
namespace trees { 

template <typename Key>
class Node {
public:
	typedef std::unique_ptr<Node<Key>> NodePtr;
	NodePtr right { nullptr };
	NodePtr left { nullptr };
	Key key;

	/** Default */
	Node() = default;

	/** Key Constructor */
	Node(Key k) 
		: key(k)
	{}

	/** Copy Constructor */
	Node(const Node &node) 
		: left(node.left->clone()) 
		, right(node.right->clone())
		, key(node.key)
	{}

	/** Move constructor */
	Node(Node && node) noexcept 
		: left(node.left->clone())
		, right(node.right->clone())
		, key(node.key)
	{}

	/** Copy Assignment Operator */
	Node & operator= (const Node &other){
		Node tmp(other);
		*this = std::move(tmp);
		return *this;
	}

	/** Move assignment operator */
	Node & operator= (Node &&other) noexcept {
		this->left = other.left->clone();
		this->right = other.right->clone();
		this->key = other.key;
		return *this;
	}

	/** Destructor */
	~Node(){}

	virtual Node *cloneImpl() const {
		return new Node(*this);
	}

	NodePtr clone() const { 
		return NodePtr(cloneImpl());
	}

};

}
}
#endif // __NODE_HPP__

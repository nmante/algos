#ifndef __HASH_HPP__
#define __HASH_HPP__
#include <functional>

namespace algos {
namespace hash {

// Hash function for table size of 

template <class T>
class Hash {

	unsigned mTableSize { 107 };
	
public:
	Hash(){}
	Hash(unsigned tableSize)
		: mTableSize(tableSize)

	{}

	unsigned int operator() (T k){
		std::hash<T> h;
		return h(k) % this->mTableSize;
	}

	unsigned int numBuckets() const { return mTableSize; }
};

template <class Key, class Value>
class HashEntry {

	Key key;
	Value value;
public:
	HashEntry(Key key, Value value)
		: key(key)
		, value(value)
	{}

	Key getKey() const { return key; }
	Value getValue() const { return value; }
	void setValue(Value v) { this->value = v; }

};

}
}

#endif // __HASH_HPP__

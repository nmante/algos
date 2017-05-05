#ifndef __HASHTABLE_HPP__
#define __HASHTABLE_HPP__
#include "hash.hpp"
#include <vector>
#include <iostream>
#include <ostream>

namespace algos {
namespace hash {

template <class Key, class Value, class H = algos::hash::Hash<Key>>
class HashTable {

	typedef HashEntry<Key, Value> Entry;
	typedef std::vector<Entry> EntryList;
	H h;
	std::vector<EntryList> mTable;

	template <class K, class V>
	class HashTableProxy {

		HashTable<K, V> &mHashTable;
		K mKey;
	public:
		HashTableProxy(HashTable<K, V> &h, const K &k)
			: mHashTable(h)
			, mKey(k)
		{}
		operator V() const {
			V v;
			bool res = this->mHashTable.get(mKey, v);
			if(res){ return v; }
			else { throw "Key: " + mKey + " not found."; }
		}

		HashTableProxy &operator=(const V& value){
			this->mHashTable.insert(mKey, value);
			return *this;
		}

	};


public:
	HashTable(){
		mTable = std::vector<EntryList>(h.numBuckets(), {});
	}

	HashTableProxy<Key, Value> operator[](const Key &k){
		return HashTableProxy<Key, Value>(*this, k);
	}

	bool get(const Key &k, Value &v){
		unsigned hashTableIndex = this->h(k);
		EntryList &bucket = this->mTable[hashTableIndex];
		for(Entry & e : bucket){
			if(e.key == k){
				v = e.value;
				return true;
			}
		}	
		return false;
	}

	bool insert(Key k, Value v){
		unsigned hashTableIndex = this->h(k);
		EntryList &bucket = this->mTable[hashTableIndex];
		for(Entry & e : bucket){
			if(e.getKey() == k){
				e.setValue(v);
				return false; 
			}
		}

		auto he = Entry(k, v);
		this->mTable[hashTableIndex].push_back(he);
		return true;
	}

	bool remove(Key k){
		unsigned hashTableIndex = this->h(k);
		EntryList bucket = this->mTable[hashTableIndex];
		for(unsigned i = 0; i < bucket.size(); i++){
			if(bucket[i].getKey() == k){
				this->mTable[hashTableIndex]
					.erase(this->mTable[hashTableIndex].begin() + i);
				return true;
			}
		}	
		return false;
	}

	friend std::ostream & operator << (std::ostream &out, HashTable<Key, Value> &h){
		out << "{";
		for(EntryList & bucket : h.mTable){
			for(Entry & e : bucket){
				out << " [ " << e.getKey() << " : " << e.getValue() << " ], "; 
			}	
		}
		out << "}";
		return out;
	}
};

}
}
#endif // __HASHTABLE_HPP__

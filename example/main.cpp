#include <iostream> 
#include <algos/algos.hpp>
#include <vector>

void search(){
	std::vector<int> v({3, 4, 10, 1, 2, 6});
	int index = algos::search::binarySearch(v, 10);
	auto vString = algos::utils::vectorToString(v);
	std::cout << "Search the vector: " << vString << std::endl;
	std::cout << "For target: 10, " << "index found: " << index << std::endl;
}
void sort(){
	std::vector<int> v({3, 4, 10, 1, 2, 6});
	algos::sort::heapSort(v);
	auto vString = algos::utils::vectorToString(v);
	std::cout << "After sorting: " << vString << std::endl;
}
void trees(){
	algos::trees::AVLTree<int> a;
	a.insert(3);
	a.insert(5);
	a.printTree(algos::trees::inOrderPrint);
	a.deleteKey(3);
}

void hash(){
	algos::hash::HashTable<int, std::string> ht;
	ht.insert(0, "Hello");
	std::cout << ht << std::endl;
	ht[0] = "hello";
	std::cout << ht << std::endl;
	ht.remove(0);
	std::cout << ht << std::endl;
}

int main(){
	search();
	sort();
	trees();
	hash();
	return 0;
}

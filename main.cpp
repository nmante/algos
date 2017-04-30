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

int main(){
	search();
	sort();
	trees();
	return 0;
}

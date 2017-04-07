#ifndef __SORT_HPP__
#define __SORT_HPP__
#include <vector>

namespace algos{
namespace sort{

/**
 * Bubble sort algorithm to sort a list in O(n^2) time
 */
void bubbleSort(std::vector<int> &arr);

/**
 * Modified bubble sort algorithm to sort a list in O(n^2) time
 */
void modifiedBubbleSort(std::vector<int> &arr);

/**
 * Selection Sort algorithms to sort a list in O(n^2) time
 */
void selectionSort(std::vector<int> &arr);

/**
 * Insertion Sort algorithm to sort a list in O(n) time, worst case O(n^2)
 */
void insertionSort(std::vector<int> &arr);

/**
 * Heap Sort algorithm to sort a list in O(n*log(n)) time
 */
void heapSort(std::vector<int> &arr);

/**
 * Merge Sort algorithm to sort a list in O(n*log(n)) time
 */
void mergeSort(std::vector<int> &arr);

/**
 * Merge Sort algorithm to sort a list in O(n*log(n)) time
 */

typedef enum {
	stack,
	queue,
	normal
} IterativeType;

void mergeSortIterative(std::vector<int> &arr);

/**
 * Quick sort algorithm to sort a list in O(n*log(n)) time
 */
void quickSort(std::vector<int> &arr);

/**
 * Quick sort algorithm iterative 
 */
void quickSortIterative(std::vector<int> &arr);

}
}

#endif // __SORT_HPP__

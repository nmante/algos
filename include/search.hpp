#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__
#include <string>
#include <vector>

namespace algos { 
namespace search {

enum functype {
       recursive = 'r', 
       iterative = 'i' 
}; 

/**
 * Conducts a binary search on a sorted array either iteratively 
 * or recursively in O(log N) time
 *
 * @param arr A sorted array of integers
 * @param target A value to search for in the array
 * @param ftype An enum type. Let's us choose recursive or iterative implementation
 * 		default is iterative
 * @return Returns the index of the 'target', -1 if doesn't exist
 */
int binarySearch(std::vector<int> arr, int target, ftype=ftype::iterative);

/**
 * Conducts a interpolation search on a sorted array either iteratively 
 * or recursively. O(log log N) time for uniform distribution, O(n) otherwise
 *
 * @param arr A sorted array of integers
 * @param target A value to search for in the array
 * @param ftype An enum type. Let's us choose recursive or iterative implementation
 * 		default is iterative
 *
 * @return Returns the index of the 'target', -1 if doesn't exist
 */
int interpolationSearch(std::vector<int> arr, int target, ftype=ftype::iterative);

/**
 * Search for the k'th smallest element in an unsorted Array in O(n) time
 *
 * @param arr An unsorted/sorted array
 * @param k The index of the smallest integer (if the array were sorted) to find
 *
 * @return Returns the value of the k'th smallest element
 */
int kthSmallest(std::vector<int> arr, int k);

/**
 * Search for the k'th largest element in an unsorted Array in O(n) time
 *
 * @param arr An unsorted/sorted array
 * @param k The index of largest integer (if the array were sorted) to find
 *
 * @return Returns the value of the k'th largest element
 */
int kthLargest(std::vector<int> arr, int k);

}}

#endif // __SEARCH_HPP__

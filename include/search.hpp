#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__
#include <string>
#include <vector>

namespace algos { 
namespace search {

enum ftype {
       recursive = 'r', 
       iterative = 'i' 
}; 

int binarySearch(std::vector<int> arr, int target, ftype=ftype::iterative);

}}

#endif // __SEARCH_HPP__

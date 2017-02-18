#include "../include/utils.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace algos {
namespace utils {

std::string vectorToString(std::vector<int> &arr){
	std::string result = "";
	for(int i = 0; i < (int)arr.size(); i++){
		result += std::to_string(arr[i]); 
		if(i != ((int)arr.size() - 1)){
			result += ", ";
		}
	}
	return result;
}

}
}

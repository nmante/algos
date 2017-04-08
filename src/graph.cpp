#include "../include/graph.hpp"
#include <iostream>
#include <queue>
#include <stack>

namespace algos {
namespace graph {


Graph::Graph(std::vector<std::string> nodes){
	for(auto node : nodes){
		adjacencyList[node] = {};
	}
}

void Graph::addEdge(std::string node1, std::string node2){
	if(adjacencyList.count(node1) == 0){
		adjacencyList[node1] = std::set<std::string>();
	}
	adjacencyList[node1].insert(node2);
}

void Graph::removeEdge(std::string node1, std::string node2){
	if(adjacencyList.count(node1) > 0){
		adjacencyList[node1].erase(node2);
		if(adjacencyList[node1].size() == 0){
			adjacencyList.erase(node1);
		}
	}

}

std::vector<std::string> Graph::bfs(std::string src, std::string end){
	std::queue<std::vector<std::string> > q;
	q.push({src});
	std::set<std::string> visited;
	std::vector<std::string> finalPath({});

	while(!q.empty()){
		// Get last path
		auto path = q.front(); q.pop();
		// Get last node
		auto node = path.back();

		// Stop if we're at the end node, 
		// otherwise keep searching neighbors if the node 
		// is unvisited
		if(node == end){
			finalPath = path;
			break;
		}else if(visited.count(node) == 0){
			for(auto neighbor : this->adjacencyList[node]){
				// create a new path including the neighbor 
				auto newPath(path);
				newPath.push_back(neighbor);
				q.push(newPath);
			}
			visited.insert(node);
		}
		
	}
	return finalPath;
}

std::vector<std::string> Graph::dfs(std::string src, std::string end){
	std::vector<std::string> finalPath({});
	std::stack<std::vector<std::string>> s;
	s.push({src});
	std::set<std::string> visited;
	while(!s.empty()){
		auto path = s.top(); s.pop();
		auto node = path.back();
		if(node == end){
			finalPath = path;
		}else if(visited.count(node) == 0){
			for(auto neighbor : this->adjacencyList[node]){
				auto newPath = path;
				newPath.push_back(neighbor);
				s.push(newPath);
			}
			visited.insert(node);
		}
	}
	return finalPath;
}

void Graph::printPath(std::string src, std::string end, SearchType sType){
	std::vector<std::string> path = {};
	switch(sType){
		case BFS:
			path = bfs(src, end);
			break;
		case DFS:
			path = dfs(src, end);
			break;
		default:
			break;
	}
	for(auto node : path){
		std::cout << node; 
		if(node != end){
			std::cout << " -> ";
		}
	}
	std::cout << std::endl;
}

void Graph::print(){
	std::cout << "-------" << std::endl;
	std::cout << "GRAPH" << std::endl;
	for(auto &pair : adjacencyList){
		auto node = pair.first;
		std::cout << node << " -> [";
		for(auto n : adjacencyList[node]){
			std::cout << n << ", ";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << "-------" << std::endl;
}

}
}

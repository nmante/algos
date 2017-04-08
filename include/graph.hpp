#ifndef __GRAPHHPP__
#define __GRAPHHPP__
#include <vector>
#include <memory>
#include <map>
#include <string>
#include <set>

namespace algos {
namespace graph {

enum SearchType{
	BFS,
	DFS
};

class Graph {
private:
	std::map<std::string, std::set<std::string> > adjacencyList;

public:
	Graph(){}
	Graph(std::vector<std::string> nodes);
	void addEdge(std::string node1, std::string node2);
	void removeEdge(std::string node1, std::string node2);
	std::vector<std::string> bfs(std::string src, std::string end);
	std::vector<std::string> dfs(std::string src, std::string end);
	void printPath(std::string src, std::string end, SearchType = BFS);
	void print();
};

}
}
#endif // __GRAPHHPP__

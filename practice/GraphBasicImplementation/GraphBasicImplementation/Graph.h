#pragma once

#include <vector>
#include <stack>

class Graph
{
private:
	int v, motherVertex;
	bool hasCycleDi, hasCycleUndi;
	std::vector<bool> visited;
	std::vector<int> visited1;
	std::vector<bool> path;
	std::vector<int> *adjL,*adjLUndi;

	std::vector<int> *transClos;

	void DFSUtil(int i);
	void topologicalSortUtil(int i,std::stack<int> &recurStack);
	void detectCycleDiUtil(int i,std::vector<bool> &path);
	void detectCycleUndiUtil(int i, int parent);
	void findMotherVertexUtil(int i);
	
public:
	bool isTree;
	Graph(int v);
	void addEdgeDi(int src, int dest);
	void addEdgeUndi(int src, int dest);
	void BFS(int src);
	void DFS();
	void topologicalSort();
	bool detectCycleDi();
	bool detectCycleUndi();
	void findMotherVertex();
	int getMotherVertex() { return motherVertex; }
	void printTransClos();
};


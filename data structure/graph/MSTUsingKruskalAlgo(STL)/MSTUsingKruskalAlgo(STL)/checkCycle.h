#pragma once
#include <vector>

class checkCycle
{
private:
	int v;
	bool isCyclic;
	std::vector<int> *adjL;
	std::vector<bool> visited;
	void hasCycleUtil(int i,int parent);
	void DFSUtil(int i);
public:
	checkCycle();
	checkCycle(int v);
	void addEdge(int src, int dest);
	bool hasCycle();
	void deleteEdge(int src, int dest);
	void DFS();
};


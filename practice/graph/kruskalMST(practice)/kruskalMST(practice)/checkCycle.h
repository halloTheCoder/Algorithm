#pragma once

#include <vector>

class checkCycle
{
private:
	int v;
	bool hasCycle;
	std::vector<int> *adjL;
	std::vector<bool> visited;
	void detectCycleUtil(int i,int parent);

public:
	checkCycle();
	checkCycle(int v);
	void addEdge(int src, int dest);
	bool detectCycle();
	void deleteEdge(int src,int dest);
};


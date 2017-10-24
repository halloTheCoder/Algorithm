#include "stdafx.h"
#include "checkCycle.h"

#include <algorithm>


checkCycle::checkCycle()
{
}

checkCycle::checkCycle(int v)
{
	this->v = v;
	adjL = new std::vector<int>[v];
	visited = std::vector<bool>(v, false);
	hasCycle = false;
}

void checkCycle::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
	adjL[dest].push_back(src);
}

bool checkCycle::detectCycle()
{
	hasCycle = false;
	visited = std::vector<bool>(v, false);
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			detectCycleUtil(i, -1);
			if (hasCycle)
				return true;
		}
	}
	return false;
}

void checkCycle::detectCycleUtil(int i,int parent)
{
	visited[i] = true;
	for (auto &n : adjL[i]) {
		if (visited[n] && n != parent) {
			hasCycle = true;
			return;
		}
		else if (!visited[n]) {
			detectCycleUtil(n, i);
		}
	}
}

void checkCycle::deleteEdge(int src, int dest)
{
	adjL[src].erase(std::remove(adjL[src].begin(), adjL[src].end(), dest), adjL[src].end());
	adjL[dest].erase(std::remove(adjL[dest].begin(), adjL[dest].end(), src), adjL[dest].end());
}



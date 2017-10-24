#include "stdafx.h"
#include "checkCycle.h"

#include <algorithm>
#include <iostream>

checkCycle::checkCycle()
{
}

checkCycle::checkCycle(int v)
{
	this->v = v;
	adjL = new std::vector<int>[v];
}

void checkCycle::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
	adjL[dest].push_back(src);
}

bool checkCycle::hasCycle()
{
	visited = std::vector<bool>(v, false);
	isCyclic = false;
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			hasCycleUtil(i, -1);
			if (isCyclic) {
				return true;
			}
		}
	}
	return false;
}

void checkCycle::hasCycleUtil(int i,int parent)
{
	visited[i] = true;
	for (auto it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (visited[*it] && (*it) != parent) {

			isCyclic = true;
		}
		if (!visited[*it]) {
			hasCycleUtil(*it, i);
		}
	}
}


void checkCycle::deleteEdge(int src, int dest)
{
	adjL[src].erase(std::remove(adjL[src].begin(),adjL[src].end(),dest),adjL[src].end());
	adjL[dest].erase(std::remove(adjL[dest].begin(), adjL[dest].end(),src), adjL[dest].end());
	//v.erase(std::remove(v.begin(), v.end(), 5), v.end());
}

void checkCycle::DFS()
{
	visited = std::vector<bool>(v, false);
	for (int i = 0; i < v; i++) {
		if(!visited[i])
			DFSUtil(i);
	}
}

void checkCycle::DFSUtil(int i)
{
	visited[i] = true;
	std::cout << i << " ";

	for (auto it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (!visited[*it]) {
			DFSUtil(*it);
		}
	}
}
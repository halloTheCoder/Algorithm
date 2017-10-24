#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	adjL = new vector<int>[v];
	visited = vector<bool>(v, false);
	hasCycle = false;
}

void Graph::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
	adjL[dest].push_back(src);
}

bool Graph::isCyclic()
{
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			isCyclicUtil(i,-1);
			if(hasCycle)
				return true;
		}
	}
	return false;
}
 
void Graph::isCyclicUtil(int i,int parent)          
{
	visited[i] = true;
	for (vector<int>::iterator it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (visited[*it] && (*it) != parent) {
			hasCycle = true;
		}
		if (!visited[*it]) {
			isCyclicUtil(*it,i);
		}
	}
}

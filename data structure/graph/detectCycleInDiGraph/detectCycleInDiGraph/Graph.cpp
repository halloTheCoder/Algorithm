#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	adjL = new vector<int>[v];
	visited = vector<bool>(v, false);
	recurStack = vector<bool>(v, false);
	hasCycle = false;
}

void Graph::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
}

bool Graph::isCyclic()
{
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			isCyclicUtil(i);
			if(hasCycle)
				return true;
		}
	}
	return false;
}
 
void Graph::isCyclicUtil(int i)          
{
	
	visited[i] = true;
	recurStack[i] = true;
	for (vector<int>::iterator it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (visited[*it] && recurStack[*it]) {
			hasCycle = true;
		}
		if (!visited[*it]) {
			isCyclicUtil(*it);
		}
	}
	recurStack[i] = false;
}

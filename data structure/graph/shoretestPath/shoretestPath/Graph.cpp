#include "stdafx.h"
#include "Graph.h"

#include<algorithm>
#include <iostream>

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<ipair>[v];
}

void Graph::addEdge(int src, int dest, int wt)
{
	adjL[src].push_back(std::make_pair(dest, wt));
	adjL[dest].push_back(std::make_pair(src, wt));
}

int Graph::shortestPath(int src,int dest)
{
	wt = 0;
	path.clear();
	visitedPath = std::vector<bool>(v, false);
	visitedPath[src] = true;
	shortestPathUtil(src,dest);
	return *(std::min_element(path.begin(), path.end()));
}

void Graph::shortestPathUtil(int i,int dest)
{
	for (auto it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (!visitedPath[it->first]) {
			wt += it->second;
			visitedPath[it->first] = true;
			if (it->first == dest) {
				//std::cout << wt << std::endl;
				path.push_back(wt);	
			}
			else {
				shortestPathUtil(it->first, dest);
			}
			wt -= it->second;
			visitedPath[it->first] = false;
		}
	}
	
}

#include "stdafx.h"
#include "Graph.h"

#include <iostream>
#include <algorithm>

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<ipair>[v];
}

void Graph::addEdge(int src, int dest, int wt)
{
	adjL[src].push_back(std::make_pair(dest,wt));
	adjL[dest].push_back(std::make_pair(src, wt));
}

void Graph::DFS(int src, int k)
{
	hasPathMoreThanK = false;
	wt = 0;
	path = std::vector<bool>(v, false);
	path[src] = true;
	DFSUtil(src, k);
}

void Graph::DFSUtil(int i, int k)
{
	if (wt > k) {
		hasPathMoreThanK = true;
		return;
	}
	for (std::vector<ipair>::iterator it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (!path[it->first]) {
			wt += it->second;
			path[it->first] = true;
			DFSUtil(it->first, k);
			wt -= it->second;
			path[it->first] = false;
		}
	}
	longestPath.push_back(wt);
}

bool Graph::pathMoreThanK(int src, int k) {
	DFS(src, k);
	return hasPathMoreThanK;
}

int Graph::getMaxWtPath() {
	return *(std::max_element(longestPath.begin(), longestPath.end()));
}

#include "stdafx.h"
#include "Graph.h"

#include <iostream>
#include <iterator>
#include <algorithm>

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<int>[v];
	visited = std::vector<bool>(v, false);
}

void Graph::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
}

void Graph::assignDirection(std::vector<ip> &undirEdges)
{
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			assignDirectionUtil(i);
		}
	}
	while (!recurStack.empty()) {
		stack.push_back(recurStack.top());
		recurStack.pop();
	}
	for (auto it = undirEdges.begin(); it != undirEdges.end(); it++) {
		if (std::distance(std::find(stack.begin(), stack.end(), (*it).first), std::find(stack.begin(), stack.end(), (*it).second)) > 0) {
			this->addEdge((*it).first, (*it).second);
		}
		else {
			this->addEdge((*it).second, (*it).first);
		}
	}
}

void Graph::assignDirectionUtil(int i)
{
	visited[i] = true;
	for (std::vector<int>::iterator it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (!visited[*it])
			assignDirectionUtil(*it);
	}
	recurStack.push(i);
}

void Graph::DFS()
{
	visited = std::vector<bool>(v, false);
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			DFSUtil(i);
		}
	}
	std::cout << std::endl;
}

void Graph::DFSUtil(int i)
{
	visited[i] = true;
	std::cout << i << " ";
	for (auto it = adjL[i].begin(); it != adjL[i].end(); it++){
		if (!visited[*it])
			DFSUtil(*it);
	}
}
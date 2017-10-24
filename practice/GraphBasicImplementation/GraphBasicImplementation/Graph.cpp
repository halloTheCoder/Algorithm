#include "stdafx.h"
#include "Graph.h"

#include <queue>
#include <iostream>
#include <algorithm>

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<int>[v];
	adjLUndi = new std::vector<int>[v];
	transClos = new std::vector<int>[v];
	visited = std::vector<bool>(v, false);
	motherVertex = -1;
}

void Graph::addEdgeDi(int src, int dest) {
	adjL[src].push_back(dest);
}

void Graph::addEdgeUndi(int src, int dest) {
	adjLUndi[src].push_back(dest);
	adjLUndi[dest].push_back(src);
}

void Graph::BFS(int src) {
	visited = std::vector<bool>(v, false);
	std::queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int u = q.front();
		
		if (visited[u]) {
			q.pop();
			continue;
		}

		std::cout << u << " ";
		visited[u] = true;
		q.pop();
		for (auto &n : adjL[u]) {
			if (!visited[n]) {
				q.push(n);
			}
		}
	}
}

void Graph::findMotherVertex() {
	visited1 = std::vector<int>(v, 0);
	for (int i = 0; i < v; i++) {
		findMotherVertexUtil(i);
		if (std::equal(visited1.begin(), visited1.end(), (std::vector<int>(v, 1)).begin())) {
			motherVertex = i;
		}
		
		transClos[i].insert(transClos[i].begin(),visited1.begin(), visited1.end());
		
		visited1 = std::vector<int>(v, 0);
	}
}

void Graph::findMotherVertexUtil(int i) {
	visited1[i] = 1;
	//std::cout << i << " ";
	for (auto &n : adjL[i]) {
		if (!visited1[n])
			findMotherVertexUtil(n);
	}
}

void Graph::printTransClos() {
	for (int i = 0; i < v; i++) {
		for (auto &n : transClos[i]) {
			std::cout << std::boolalpha << n << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::DFS() {
	visited = std::vector<bool>(v, false);
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			DFSUtil(i);
		}
	}
}

void Graph::DFSUtil(int i) {
	visited[i] = true;
	std::cout << i << " ";
	for (auto &n : adjL[i]) {
		if (!visited[n])
			DFSUtil(n);
	}
}

void Graph::topologicalSort()
{
	visited = std::vector<bool>(v, false);
	
	std::stack<int> recurStack;

	for (int i = 0; i < v; i++) {
		if (!visited[i])
			topologicalSortUtil(i,recurStack);
	}
	while (!recurStack.empty()) {
		std::cout << recurStack.top() << " ";
		recurStack.pop();
	}
}


void Graph::topologicalSortUtil(int i, std::stack<int> &recurStack) {
	visited[i] = true;
	for (auto &n : adjL[i]) {
		if (!visited[n]) {
			topologicalSortUtil(n, recurStack);
		}
	}
	recurStack.push(i);
}

bool Graph::detectCycleDi()
{
	hasCycleDi = false;
	visited = std::vector<bool>(v, false);
	path = std::vector<bool>(v, false);
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			detectCycleDiUtil(i, path);
			if (hasCycleDi)
				return true;
		}
	}
	return false;
}

void Graph::detectCycleDiUtil(int i,std::vector<bool> &path)
{
	path[i] = true;
	visited[i] = true;
	for (auto &n : adjL[i]) {
		if (path[n] && visited[n]) {
			hasCycleDi = true;
			return;
		}
		else if (!visited[n]) {
			detectCycleDiUtil(n, path);
		}
	}
	path[i] = false;
}

bool Graph::detectCycleUndi()
{
	hasCycleUndi = false;
	isTree = true;
	visited = std::vector<bool>(v, false);

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			detectCycleUndiUtil(i, -1);
			if (hasCycleUndi)
				return true;
			if (!std::equal(visited.begin(), visited.end(), (std::vector<bool>(v, 1)).begin()))
				isTree = false;
		}
	}
	return false;
}

void Graph::detectCycleUndiUtil(int i, int parent)
{
	visited[i] = true;
	for (auto &n : adjLUndi[i]) {
		if (visited[n] && n != parent) {
			hasCycleUndi = true;
			return;
		}
		if(!visited[n])
			detectCycleUndiUtil(n, i);
	}
}
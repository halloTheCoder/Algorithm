#include "stdafx.h"
#include "Graph.h"

#include <vector>
#include <iostream>
#include <queue>

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<int>[v];
	isTree = true;
	motherVertex = -1;
}

void Graph::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
}

void Graph::BFS()
{
	std::vector<bool> visited(v, 0);
	std::queue<int> queue;
	for (int i = 0; i < v; i++) {
		visited[i] = 1;
		queue.push(i);

		while (!queue.empty()) {
			int i = queue.front();
			std::cout << i << " ";
			queue.pop();
			for (auto it = adjL[i].begin(); it != adjL[i].end(); it++) {
				if (visited[*it])
					isTree = false;
				if (!visited[*it]) {
					visited[*it] = 1;
					queue.push(*it);
				}
			}
		}
		if (std::equal(visited.begin(), visited.end(), (new std::vector<bool>(v, 1))->begin())) {
			motherVertex = i;
		}
		std::cout << std::endl;
		visited = std::vector<bool>(v, 0);
	}
}

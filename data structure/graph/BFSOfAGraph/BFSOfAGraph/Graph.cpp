#include "stdafx.h"
#include "Graph.h"

#include <iostream>
#include <vector>
#include <queue>

Graph::Graph(int v)
{
	this->v = v;
	adj = new std::vector<int>[v];
}

void Graph::addEdge(int src, int des)
{
	adj[src].push_back(des);
}

void Graph::BFS(int s)
{
	std::vector<bool> visited(v, 0);
	std::queue<int> queue;
	visited[s] = 1;

	queue.push(s);

	while (!queue.empty()) {
		s = queue.front();
		queue.pop();
		std::cout << s << " ";
		
		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it visited
		// and enqueue i
		for (auto it = adj[s].begin(); it != adj[s].end(); it++) {
			if (!visited[*it]) {
				visited[*it] = 1;
				queue.push(*it);
			}
		}
	}
}



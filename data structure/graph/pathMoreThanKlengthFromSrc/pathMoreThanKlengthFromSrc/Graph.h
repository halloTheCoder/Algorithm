#pragma once
#include <vector>
#include <utility>

#define ipair std::pair<int,int>

class Graph
{
private:
	int v;
	bool hasPathMoreThanK;
	int wt;
	std::vector<ipair> *adjL;
	std::vector<bool> path;
	std::vector<int> longestPath;
	void DFSUtil(int i,int k);
public:
	Graph(int v);
	void addEdge(int src, int dest, int wt);
	void DFS(int src,int k);
	bool pathMoreThanK(int src, int k);
	int getMaxWtPath();
};


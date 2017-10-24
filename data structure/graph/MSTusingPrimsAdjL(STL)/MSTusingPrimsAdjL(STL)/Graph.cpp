#include "stdafx.h"
#include "Graph.h"

using namespace std;

Graph::Graph(int v)
{
	this->v = v;
	mstSet = vector<bool>(v, false);
	parent = vector<int>(v, -1);
	adjL = new vector<ip>[v];
	key = vector<int>(v, INT_MAX);
}

void Graph::addEdge(int src, int dest, int w)
{
	adjL[src].push_back(make_pair(dest, w));
	adjL[dest].push_back(make_pair(src, w));
}

void Graph::printMST()
{
	std::cout << "WeiGHt  ::  EdgE" << std::endl;
	for (int i = 1; i < v; i++) {
		std::cout << key[i] << " :: " << parent[i] << " - " << i << endl;
	}
}

void Graph::primMST()
{
	std::priority_queue<ip, vector<ip>, std::greater<ip> > pq;
	int src = 0;
	pq.push(make_pair(0, src));
	key[src] = 0;
	while (!pq.empty()) {
		// The first vertex in pair is the minimum key
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted key (key must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();
		mstSet[u] = true;
		for (vector<ip>::iterator it = adjL[u].begin(); it != adjL[u].end(); it++){
			// Get vertex label and weight of current adjacent
			// of u.
			int v = (*it).first;							  //for adjL phela vertex h fir weight
			int weight = (*it).second;
			if (mstSet[v] == false && weight < key[v]) {      //yaha mstSet use kar rahe h kyuki for visited vertex humlog
				parent[v] = u;									  			 //already check kar chuke h wo edge
				key[v] = weight;
				pq.push(make_pair(weight,v));
			}
		}
	}
	printMST();
}

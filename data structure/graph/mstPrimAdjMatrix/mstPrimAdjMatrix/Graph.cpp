#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	mstSet = vector<bool>(v, false);
	parent = vector<int>(v, -1);
	key = vector<int>(v, INT_MAX);
	key[0] = 0;
}

int Graph::minKey()           //IMP STEP
{
	int min = INT_MAX,min_index;
	for (int i = 0; i < v; i++) {
		if (mstSet[i] == false && key[i] < min) {
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void Graph::primMST(int graph[][5])
{
	for (int count = 0; count < v - 1; count++) {
		int u = minKey();
		mstSet[u] = true;
		for (int i = 0; i < v; i++) {
			if (graph[u][i] && mstSet[i] == false && graph[u][i] < key[i]) {
				parent[i] = u;          //basically ek vertex ke har taraf se jaana h aur uska parent dundhana h for min weight
				key[i] = graph[u][i];
			}
		}
	}
	printMST(graph);
}

void Graph::printMST(int graph[][5])
{
	cout << "EDgE  ::  WeIGht" << endl;
	for (int i = 1; i < v; i++) {
		cout << parent[i] << " - " << i << " :: " << graph[i][parent[i]] << endl;   //in graph[][] can use first parent[i] also as undiGraph
	}
}

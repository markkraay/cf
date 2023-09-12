#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void identify(vector<int> const&& edges, int V) {
	int one_edge = 0;
	int two_edges = 0;
	int V_edges = 0;
	for (int i : edges) {
		if (i == 1) one_edge++;
		else if (i == 2) two_edges++;
		else if (i == V - 1) V_edges++;
	}
	// Each node has one connecction => bus 
	// Each node has two connections => ring
	// One node has n - 1 connections and the other ones have one connection => star
	if (two_edges == V) cout << "ring topology" << endl;
	else if (two_edges == V - 2 && one_edge == 2) cout << "bus topology" << endl;
	else if (one_edge == V - 1 && V_edges == 1) cout << "star topology" << endl;
	else cout << "unknown topology" << endl;
}

int main() {
	int V, E, v1, v2;
	cin >> V >> E;
	vector<int> edges(V+1);
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		edges[v1]++;
		edges[v2]++;
	}
	identify(move(edges), V);
}
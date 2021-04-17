/*
	Problem 038
	ID : ARCTIC

	this problem is able to be solved by kruskal algorithm because it's almost same as minimum spanning tree
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

// number of nodes
static int numNodes;
// all nodes are equivalent to position of bases
static pair<double, double> nodes[100];
// all edges are equivalent to distances of node to node
static double edges[100][100];

// get distances of node to node
static double getDistance(pair<double, double> pos1, pair<double, double> pos2) {
	return sqrt(pow(pos2.first - pos1.first, 2) + pow(pos2.second - pos1.second, 2));
}

// return if all distances of bases to bases are shorter than given distance when all bases should be linked
static bool decision(double distance) {
	vector<bool> visited(numNodes, false); 
	// enqueue first node
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;
	// breadth first search
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		seen++;
		for (int i = 0; i < numNodes; i++) {
			// only nodes which distance between current node is shorter than given distance
			if (!visited[i] && edges[here][i] <= distance) {
				visited[i] = true;
				q.push(i);
			}
		}
	}

	return seen == numNodes;
}

// get minimum distance
static double optimize() {
	double low = 0, high = 1416.00;
	for (int it = 0; it < 100; it++) {
		double mid = (low + high) / (double)2;
		if (decision(mid))
			high = mid;
		else
			low = mid;
	}
	return high;
}

void p038() {
	cout.precision(2);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);

	AutomatedInput Input;
	Input.set(
		"2 "
		"5 "
		"0 0 "
		"1 0 "
		"1 1 "
		"1 2 "
		"0 2 "
		"6 "
		"1.0 1.0 "
		"30.91 8 "
		"4.0 7.64 "
		"21.12 6.0 "
		"11.39 3.0 "
		"5.31 11.0 "
	);

	int T;
	Input >> T;

	for (int trial = 0; trial < T; trial++) {

		Input >> numNodes;
		for (int i = 0; i < numNodes; i++) {
			pair<double, double> tmp;
			Input >> tmp.first >> tmp.second;
			nodes[i] = tmp;
		}

		for (int i = 0; i < numNodes; i++) {
			for (int j = 0; j < numNodes; j++) {
				edges[i][j] = getDistance(nodes[i], nodes[j]);
			}
		}

		cout << optimize() << endl;
	}
}
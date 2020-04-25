/*
	Graph. It is insist of vertices(nodes), and edge, tagging between two nodes.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "../Base/Base.h"
#include "../Linked_Structure/Pointer_Based_Linear_List/Pointer_Based_Linear_List.h"

// Constantualized vertices name.
enum VertexType {A, B, C, D, E, F, G, H, I, J};

// Graph datatype. implemented as Adjacency list, and it is undirected graph
typedef struct {
	int numV;	// Number of vertex
	int numE;	// Number of edges
	Ptr_LinearList* adjList;	// Information of edges
	int* visitInfo;
} Graph;

// Make and return an initialized graph.
static Graph MakeGraph(int nodeSize);

// Add an edge that has two given vertex on its end on graph
static void AddEdge(Graph* g, VertexType from, VertexType to);

// Remove an edge that has two given vertex on its end from graph
static void RemoveEdge(Graph* g, VertexType from, VertexType to);

// Print information about all vertices and edges of graph
static void Print(Graph* g);

// Remove graph
static void Terminate(Graph* g);

// Main function of graph
void Graph_Main();

#endif
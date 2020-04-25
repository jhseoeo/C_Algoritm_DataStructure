/*	
	Couple of graph search algorithm, Breath First Search, and Depth First Search.
*/

#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H

#include "../Base/Base.h"
#include "./Graph.h"
#include "../Linked_Structure/Pointer_Based_Linear_List/Pointer_Based_Linear_List.h"
#include "../Simple_Data_Structure/LinkedStack/LinkedStack.h"
#include "../Simple_Data_Structure/LinkedQueue/LinkedQueue.h"

// Reset the visit info of given graph.
static void ResetVisitInfo(Graph* g);

// Visit a virtex and check it if it was first visit.
static int VisitVertex(Graph* g, VertexType v);

// Depth First Search. 
void Depth_First_Search(Graph* g, VertexType Sv);

// Breath First Search.
void Breadth_First_Search(Graph* g, VertexType Sv);

#endif
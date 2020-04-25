#include "Graph.h"
#include "./Search.h"

static Graph MakeGraph(int nodeSize) {
	Graph graph;
	graph.numV = nodeSize;
	graph.numE = 0;
	graph.adjList = (Ptr_LinearList*)malloc(sizeof(Ptr_LinearList) * nodeSize);
	graph.visitInfo = (int*)malloc(sizeof(int) * nodeSize);
	for (int i = 0; i < nodeSize; i++) {
		graph.adjList[i] = MakePtrLinearList_p();
		graph.visitInfo[i] = FALSE;
	}
	
	return graph;
}

static void AddEdge(Graph* g, VertexType from, VertexType to) {
	if (from == to)
		return;
	
	g->numE += 1;
	InsertRear_p(g->adjList + from, to);
	InsertRear_p(g->adjList + to, from);
}

static void RemoveEdge(Graph* g, VertexType from, VertexType to) {
	if (from == to)
		return;
	
	if (MoveCur_p(g->adjList + from, to) != NULL) {
		RemoveCursor_p(g->adjList + from);
		MoveCur_p(g->adjList + to, from);
		RemoveCursor_p(g->adjList + to);
		g->numE -= 1;
	}
}

static void Print(Graph* g) {
	for(int i = 0; i < g->numV; i++) {
		printf("%c : ", 'A' + i);
		PrintAll_p(g->adjList[i]);
		printf("\n");
	}
}

static void Terminate(Graph* g) {
	for(int i = 0; i < g->numV; i++) {
		Terminate_p(g->adjList + i);
	}
	free(g->adjList);
}

static void GetInput(char &i1, char &i2) {
	printf("First Vertex\n"); 
	printf(">>"); scanf("%c", &i1); getchar();

	printf("Second Vertex\n");
	printf(">>"); scanf("%c", &i2); getchar();
	
}

void Graph_Main() {
	Graph graph = MakeGraph(10);
	printf("PriorityQueue Created.\n");
	int input;
	char temp1, temp2;
	VertexType a1, a2;
	while (1) {
		system(CLEAR);
		Print(&graph);
		printf("Menu\n");
		printf("1. Add Edge\n");
		printf("2. Remove Edge\n");
		printf("3. Depth-First Search\n");
		printf("4. Breadth-First Search\n");
		printf("5. End\n");
		printf(">> "); scanf("%d", &input); getchar(); printf("\n");

		switch (input) {
		case 1:
			GetInput(temp1, temp2);
			a1 = (VertexType)(temp1 - 'A');
			a2 = (VertexType)(temp2 - 'A');
			AddEdge(&graph, a1, a2);
			break;
		case 2:
			GetInput(temp1, temp2);
			a1 = (VertexType)(temp1 - 'A');
			a2 = (VertexType)(temp2 - 'A');
			RemoveEdge(&graph, a1, a2);
			break;
		case 3:
			printf("Enter the starting point\n");
			printf(">> "); scanf("%c", &temp1); getchar(); 
			a1 = (VertexType)(temp1 - 'A');
			Depth_First_Search(&graph, a1);
			sleep(1500);
			break;
		case 4:
			printf("Enter the starting point\n");
			printf(">> "); scanf("%c", &temp1); getchar();
			a1 = (VertexType)(temp1 - 'A');
			Breadth_First_Search(&graph, a1);
			sleep(1500);
			break;
		case 5:
			Terminate(&graph);
			goto ENDLOOP;
			break;
		default: break;
		}
	} ENDLOOP:;
}
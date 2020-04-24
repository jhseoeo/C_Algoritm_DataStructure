#include "Search.h"

static int ResetVisitInfo(Graph* g) {
	for (int i = 0; i < g->numV; i++) {
		g->visitInfo[i] = 0;
	}
}

static int VisitVertex(Graph* g, VertexType v) {
	if (g->visitInfo[v] == 0) {
		g->visitInfo[v] = 1;
		return TRUE;
	}
	return FALSE;
}

static void DFS_exec(Graph* g, VertexType v) {
	PllNode* ptr = g->adjList[v].head;
	if (ptr != NULL) {
		if (VisitVertex(g, (VertexType)ptr->data) == TRUE) {
			DFS_exec(g, (VertexType)ptr->data);
		}
		ptr = ptr->next;
	}
}

static void DFS_exec(Graph* g, VertexType v) {
	printf("%c ", v + 'A');

	PllNode* ptr = g->adjList[v].head;
	while (ptr != NULL) {
		if (VisitVertex(g, (VertexType)ptr->data) == TRUE) {
			DFS_exec(g, (VertexType)ptr->data);
		}
		ptr = ptr->next;
	}
}

void Depth_First_Search(Graph* g, VertexType Sv) {
	VisitVertex(g, Sv);
	DFS_exec(g, Sv);
}


static void BFS_exec(Graph* g, VertexType v) {
	printf("%c ", v + 'A');

	PllNode* ptr = g->adjList[v].head;
	VertexType* Visited = (VertexType*)malloc(g->adjList[v].size * sizeof(VertexType));
	int idx = 0;
	while(ptr != NULL) {
		if (VisitVertex(g, (VertexType)ptr->data) == TRUE) {
			Visited[idx++] = 
		}
		ptr = ptr->next;
	}
	 

}

void Breadth_First_Search(Graph* g, VertexType Sv) {
	VisitVertex(g, Sv);
	BFS_exec(g, Sv);
}
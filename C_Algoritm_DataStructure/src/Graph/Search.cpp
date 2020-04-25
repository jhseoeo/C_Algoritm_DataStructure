#include "Search.h"

static void ResetVisitInfo(Graph* g) {
	for (int i = 0; i < g->numV; i++) {
		g->visitInfo[i] = FALSE;
	}
}

static int VisitVertex(Graph* g, VertexType v) {
	if (g->visitInfo[v] == FALSE) {
		g->visitInfo[v] = TRUE;
		printf("%c ", v + 'A');
		return TRUE;
	}
	return FALSE;
}

void Depth_First_Search(Graph* g, VertexType Sv) {
	LinkedStack stack = MakeLinkedStack_s();
	int visitV = Sv;
	int nextV;

	VisitVertex(g, Sv);
	Push_s(&stack, Sv);

	while (g->adjList[visitV].size != 0) {
		int visitFlag = FALSE;

		for (PllNode* ptr = g->adjList[visitV].head; ptr != NULL; ptr = ptr->next) {
			nextV = ptr->data;
			if (VisitVertex(g, (VertexType)nextV) == TRUE) {
				Push_s(&stack, visitV);
				visitV = nextV;
				visitFlag = TRUE;
				break;
			}
		}

		if (visitFlag == FALSE) {
			if (stack.stk == NULL)
				break;
			else
				Pop_s(&stack, &visitV);
		}
	}
	
	ResetVisitInfo(g);
	Terminate_s(&stack);
}

void Breadth_First_Search(Graph* g, VertexType Sv) {
	LinkedQueue queue = MakeLinkedQueue_q();
	int visitV = Sv;
	int nextV;

	VisitVertex(g, Sv);

	while (g->adjList[visitV].size != 0) {
		
		for(PllNode* ptr = g->adjList[visitV].head; ptr != NULL; ptr = ptr->next) {
			nextV = ptr->data;
			if (VisitVertex(g, (VertexType)nextV) == TRUE) {
				Enque_q(&queue, nextV);
			}
		}

		if (queue.front == NULL)
			break;
		else
			Deque_q(&queue, &visitV);
	}

	ResetVisitInfo(g);
	Terminate_q(&queue);
}				
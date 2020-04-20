#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"
int main()
{
	struct Vertex Vertex;
	struct Edge Edge;
	struct Graph Graph;
	struct Tree Tree;
	printf("enter the number of vertices in the graph");
	scanf("%d", &Graph.number_of_vertices);
	int max_number_of_edges = (Graph.number_of_vertices * (Graph.number_of_vertices - 1)) / 2;
	struct Edge* edges = malloc(max_number_of_edges * sizeof(Edge));
	Graph.edges = edges;
	struct Edge* edges2 = malloc(max_number_of_edges * sizeof(Edge));
	Tree.edges = edges2;
	struct Vertex* vertices = malloc(Graph.number_of_vertices * sizeof(Vertex));
	Graph.vertices = vertices;
	Graph=scan_matrix(Graph);
	sort_edges(Graph);
	Tree.number_of_edges = 0;
	Tree=algoritm(Graph,Tree);
	for (int i = 0; i < Tree.number_of_edges; i++)
	{
		printf("%d\n", Tree.edges[i].value);
	}
	return 0;
}
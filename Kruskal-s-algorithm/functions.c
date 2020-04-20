#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
Graph scan_matrix(Graph Graph)
{
	printf("enter graph as adjacency matrix\n");
	Graph.number_of_edges = 0;
	int value;
	for (int i = 0; i < Graph.number_of_vertices; i++)
	{
		Graph.vertices[i].group = i;
		Graph.vertices[i].number = i;

	}
	for (int i = 0; i < Graph.number_of_vertices; i++)
	{
		for (int j = 0; j < Graph.number_of_vertices; j++)
		{
			scanf("%d", &value);
			if (value != 0 && j>=i+1)
			{
				Graph.edges[Graph.number_of_edges].first_vertex = i;
				Graph.edges[Graph.number_of_edges].second_vertex = j;
				Graph.edges[Graph.number_of_edges].value = value;
				//printf("\nT===%d\t%d\t%d\n", Graph.edges[Graph.number_of_edges].first_vertex, Graph.edges[Graph.number_of_edges].second_vertex,Graph.edges[Graph.number_of_edges].value);
				Graph.number_of_edges++;
			}
			else continue;
		}
	}
	return(Graph);
}
void sort_edges(Graph Graph)
{
	Edge temp;
	int j;
	for (int i = 1; i < Graph.number_of_edges; i++)
	{
		temp = Graph.edges[i];
		j = i - 1;
		while (j >= 0 && Graph.edges[j].value > temp.value)
		{
			Graph.edges[j + 1] = Graph.edges[j];
			j--;
		}
		Graph.edges[j + 1] = temp;
	}
}
Tree algoritm(Graph Graph,Tree Tree)
{
	int edge_number = 0;
	while (Tree.number_of_edges < Graph.number_of_vertices-1)
	{
		if (Graph.vertices[Graph.edges[edge_number].first_vertex].group != Graph.vertices[Graph.edges[edge_number].second_vertex].group)
		{
			int temp = Graph.vertices[Graph.edges[edge_number].second_vertex].group;
			for (int i = 0; i < Graph.number_of_vertices; i++)
			{
				if (Graph.vertices[i].group == temp)
				{
					Graph.vertices[i].group = Graph.vertices[Graph.edges[edge_number].first_vertex].group;
				}
			}
			Tree.edges[Tree.number_of_edges] = Graph.edges[edge_number];
			Tree.number_of_edges++;
		}
		edge_number++;
	}
	return(Tree);
}
void print_tree(Tree Tree)
{
	printf("minimum spanning tree adjacency matrix:\n");
	int** b = (int**)malloc(Tree.number_of_vertices * sizeof(int*));//выдел€ю пам€ть дл€ 2 мерного массива
	for (int i = 0; i < Tree.number_of_vertices; i++)
	{
		b[i] = (int*)malloc(Tree.number_of_vertices * sizeof(int));
		for (int j = 0; j < Tree.number_of_vertices; j++)
		{
			b[i][j] = 0;
		}
	}
	for (int i = 0; i < Tree.number_of_edges; i++)
	{
		b[Tree.edges[i].first_vertex][Tree.edges[i].second_vertex] = Tree.edges[i].value;
		b[Tree.edges[i].second_vertex][Tree.edges[i].first_vertex] = Tree.edges[i].value;
	}
	for (int i = 0; i < Tree.number_of_vertices; i++)
	{
		for (int j = 0; j < Tree.number_of_vertices; j++)
		{
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
}
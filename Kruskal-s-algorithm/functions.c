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
				Graph.edges[Graph.number_of_edges].first_vertex = Graph.vertices[i];
				Graph.edges[Graph.number_of_edges].second_vertex = Graph.vertices[j];
				Graph.edges[Graph.number_of_edges].value = value;
				Graph.number_of_edges++;
			}
			else continue;
		}
	}
	return(Graph);
}
void sort_edges(Graph Graph)
{
	int temp,j;
	for (int i = 1; i < Graph.number_of_edges; i++)
	{
		temp = Graph.edges[i].value;
		j = i - 1;
		while (j >= 0 && Graph.edges[j].value > temp)
		{
			Graph.edges[j + 1].value = Graph.edges[j].value;
			j--;
		}
		Graph.edges[j + 1].value = temp;
	}
	return;
}
Tree algoritm(Graph Graph,Tree Tree)
{
	int edge_number = 0;
	while (Tree.number_of_edges < Graph.number_of_vertices)
	{
		if (Graph.vertices[Graph.edges[edge_number].first_vertex.number].group != Graph.vertices[Graph.edges[edge_number].second_vertex.number].group)
		{
			for (int i = 0; i < Graph.number_of_vertices; i++)
			{
				if (Graph.vertices[i].group == Graph.vertices[Graph.edges[edge_number].second_vertex.number].group)
				{
					Graph.vertices[i].group == Graph.vertices[Graph.edges[edge_number].first_vertex.number].group;
				}
			}
			Tree.edges[Tree.number_of_edges] = Graph.edges[edge_number];
			Tree.number_of_edges++;
		}
		edge_number++;
	}
	return(Tree);
}
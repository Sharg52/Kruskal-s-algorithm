#ifndef FUNCTIONS_H
#define FUNCTIONS_H
typedef struct Vertex
{
	int number;
	int group;
}Vertex;
typedef struct Edge
{
	int first_vertex;
	int second_vertex;
	int value;
}Edge;

typedef struct Graph
{
	int number_of_edges;
	int number_of_vertices;
	Edge* edges;
	Vertex* vertices;
}Graph;
typedef struct Tree
{
	int number_of_vertices;
	int number_of_edges;
	Edge* edges;
}Tree;
Tree algoritm(Graph Graph,Tree Tree);
Graph scan_matrix(Graph Graph);
void sort_edges(Graph Graph);
void print_tree(Tree Tree);
#endif 
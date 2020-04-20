#ifndef FUNCTIONS_H
#define FUNCTIONS_H
typedef struct Vertex
{
	int number;
	int group;
}Vertex;
typedef struct Edge
{
	Vertex first_vertex;
	Vertex second_vertex;
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
	int number_of_edges;
	Edge* edges;
}Tree;
Tree algoritm(Graph Graph,Tree Tree);
Graph scan_matrix(Graph Graph);
void sort_edges(Graph Graph);
enum Action { GET = 1, PUT, STOP, };
enum Type { INT = 0, DOUBLE, STRING };
enum Flag { NEW, OLD };
//int get(Dumb_dict Dumb_dict, char* temp_key);
//void keyprint(Dumb_dict Dumb_dict, int temp);
enum Type whattype(char* temp_value);
//enum Flag put(Dumb_dict Dumb_dict, char* temp_key, char* temp_value);
#endif 
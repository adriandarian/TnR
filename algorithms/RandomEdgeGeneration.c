#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VERTICES 30
#define MAX_EDGES 10

typedef unsigned char vertex;

int main() {
	/*number of nodes in a graph*/
	srand(time(NULL));
	int numberOfVertices = rand() % MAX_VERTICES;
	/*number of maxium edges a vertex can have*/
	srand(time(NULL));
	int maxNumberOfEdges = rand() % MAX_EDGES;
	/*graphs are 2 dimensional array of pointers*/
	if (numberOfVertices == 0)
		numberOfVertices++;
	vertex ***graph;
	printf("Total Vertices = %d, Max # of Edges = %d\n", numberOfVertices, maxNumberOfEdges);
	/*genreate a dynamic array of random size*/
	if ((graph = (vertex ***)malloc(sizeof(vertex **) * numberOfvertices)) == NULL) {
		printf("Could not allocate memory for the graph\n");
		exit(1);
	}
	/*generate space for edges*/
	int vertexCounter = 0;
	/*generate space for vertices*/
	int edgeCounter = 0;
	for (vertexCounter = 0; vertexCounter < numberOfVertices; vertexCounter++) {
		if ((graph[vertexCounter] = (vertex **)malloc(sizeof(vertex *) * maxNumberOfEdges)) == NULL) { 
			printf("Could not allocate memory for edges\n");
			exit(1);
		}
		for (edgeCounter = 0; edgeCounter < maxNumberOfEdges; edgeCounter++) {
			if ((graph[vertexCounter][edgeCounter] = (vertex *)malloc(sizeof(vertex))) == NULL) {
				printf("Could not allocate memory for vertex\n");
				exit(1);
			}
		}
	}
	/*start linking graph. All vertices need not have same number of links*/
	vertexCounter = 0;
	edgeCounter = 0;
	for (vertexCounter = 0; vertexCounter < numberOfVertices; vertexCounter++) {
		printf("%d:\t", vertexCounter);
		for (edgeCounter = 0; edgeCounter < maxNumberOfEdges; edgeCounter++) {
			if (rand() % 2 == 1) {  /*link the vertices*/
				int linkedVertex = rand() % numberOfVertices;
				graph[vertexCounter][edgeCounter] = graph[linkedVertex];
				printf("%d, ", linkedVertex);
			} else /*make the link NULL*/
				graph[vertexCounter][edgeCounter] == NULL;
		}
		printf("\n");
	}
	return 1;
}
/*
Total Vertices = 18, Max # of Edges = 8
0:   12, 9, 6,
1:   6, 1,
2:   7, 4, 1, 9, 3, 5,
3:   8, 13, 1, 12, 13, 6,
4:   5, 11,
5:   6, 6, 6, 5, 11,
6:   6, 5, 16, 10, 1, 13,
7:   14, 13, 13, 12,
8:   6, 12, 4,
9:   6, 17, 4, 10,
10:  6, 6, 11, 10,
11:  2, 16,
12:  3, 15, 7,
13:  6, 15, 3, 9, 15,
14:  4, 10,
15:  5, 4, 3,
16:  17, 11,
17:  0, 7,
*/

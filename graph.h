#ifndef GRAPH_H
#define GRAPH_H
//This class represents a graph object by maintaining an adjacency matrix.
//Any unconnected vertices are represented by
class Graph {
public:
    Graph(int vertices) {
        int a[vertices][vertices];
        for (int i=0; i<vertices; i++) {
            for (int j=0; j<vertices; j++) {
                 a[i][j] INT_MAX;
            }
        }
        adjMatrix = &a;
    }
    ~Graph();
    void addEdge(int u, int v, int weight);
    void primMST();  // Must print MST edges and total weight

private:
    int* adjMatrix[][];
    int numVertices;
};

#endif
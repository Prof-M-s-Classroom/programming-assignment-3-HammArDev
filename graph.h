#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>;
#include "heap.h";
//This class represents a graph object by maintaining an adjacency matrix.
//Any unconnected vertices are represented by
class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix= new int* [vertices];
        for (int i=0; i<vertices; i++) {
            adjMatrix[i] = new int[vertices];
        }
        for (int i=0; i<vertices; i++) {
            for (int j=0; j<vertices; j++) {
                adjMatrix[i][j] = INT_MAX;
            }
        }
    }
    ~Graph();
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
    }
    // Must print MST edges and total weight
    void primMST() {
        int totalweight = 0;
        int* vertices = new int[numVertices];
        for (int i=0; i<numVertices; i++) {
            if (i=0) {
                vertices[i]=0;
            }else {
                vertices[i] = -1;
            }
        }
        int currentPtr = 0;
        //Create a MinHeap
        MinHeap min(numVertices);
        //Keep going until vertices is full
        while (currentPtr<numVertices) {
            //Start at vertex 0

            //Process node connections(while skipping redundancies) and make a MinHeap
            //Insert with the key being the minimum weight

            //Add the lowest weight vertex to your tree
            int* rawOutput = min.extractMin();
            vertices[currentPtr] = rawOutput[0];
            totalweight+=rawOutput[1];
            currentPtr++;
            //Process all new edges, and update the MinHeap accordingly
        }
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif
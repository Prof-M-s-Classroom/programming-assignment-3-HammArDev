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
        //Initializing the solution set, totalWeight, and edges
        //We always start at vertex 0
        int totalWeight = 0;
        int* vertices = new int[numVertices];
        int** edges = new int* [numVertices-1];
        int newestAddition;
        for (int i=0; i<numVertices-1; i++) {
            edges[i]=new int[2];
        }
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
        //Start at vertex 0
        vertices[currentPtr] = 0;
        currentPtr++;
        newestAddition=0;
        //Keep going until vertices is full
        while (currentPtr<numVertices) {

            //Process node connections(while skipping redundancies) and make a MinHeap
            //Insert with the key being the minimum weight
            for (int i=0; i<numVertices; i++) {
                if (adjMatrix[newestAddition][i]==INT_MAX){
                    continue;
                }else {
                    for (int j=0; j<currentPtr; j++) {
                        if (vertices[j]==adjMatrix[newestAddition][i]) {
                            continue;
                        }
                    }

                }
            }
            //Add the lowest weight vertex to your tree
            int* rawOutput = min.extractMin();
            vertices[currentPtr] = rawOutput[0];
            totalWeight+=rawOutput[2];
            edges[currentPtr][0]=rawOutput[1];
            edges[currentPtr][1]=rawOutput[0];
            currentPtr++;
            //Process all new edges, and update the MinHeap accordingly
        }
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif
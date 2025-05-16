#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include "heap.h"
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
    ~Graph() {
        delete adjMatrix;
    }
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
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
            if (i==0) {
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
        currentPtr;
        newestAddition=0;
        //Keep going until vertices is full
        while (currentPtr<numVertices-1) {

            //Process node connections(while skipping redundancies) and make a MinHeap
            //Insert with the key being the minimum weight
            for (int i=0; i<numVertices; i++) {
                if (adjMatrix[newestAddition][i]==INT_MAX){
                    continue;
                }else {
                    bool insert = true;
                    for (int j=0; j<currentPtr; j++) {
                        if (vertices[j]==i) {
                            insert=false;
                        }
                    }
                    if (insert) {
                        min.insert(i, newestAddition, adjMatrix[newestAddition][i]);
                    }
                }
            }
            //Add the lowest weight vertex to your tree
            //min.printheap();
            int* rawOutput = min.extractMin();
            vertices[currentPtr+1] = rawOutput[0];
            newestAddition=rawOutput[0];
            totalWeight+=rawOutput[2];
            edges[currentPtr][0]=rawOutput[1];
            edges[currentPtr][1]=rawOutput[0];
            currentPtr++;
            //Process all new edges, and update the MinHeap accordingly
        }
        for (int i=0; i<numVertices-1; i++) {
            std::cout<<edges[i][0]<<"--"<<edges[i][1]<<std::endl;
        }
        std::cout<<"Min spanning tree is "<<totalWeight<<std::endl;
    }
    void printGraph() {
        for (int i=0; i<numVertices; i++)  {
            for (int j=0; j<numVertices; j++) {
                if (adjMatrix[i][j]==INT_MAX) {
                    std::cout<<"INF  ";
                }else {
                    printf("%-5d", adjMatrix[i][j]);
                }
            }
            std::cout<<std::endl;
        }
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif
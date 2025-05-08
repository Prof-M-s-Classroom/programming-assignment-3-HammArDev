[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Hamish Arora

## Description
This program does 2 things:
- Represent an undirected, weighted graph 
  - The constructor builds a graph with vertices labeled '0', '1', '2', ... 'n'
  - The addEdge() method creates the corresponding edge in the adjacency matrix
- Return a minimum spanning tree using Prim's Algorithm
  - This greedy algorithm 'builds' a tree by adding the lowest weight cutting edge to the tree

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log(n))       |
| Extract Min          | O(1)            |
| Decrease Key         |                 |
| Prim’s MST Overall   |                 |

_Explain why your MST implementation has the above runtime._

## Test Case Description

Input:  
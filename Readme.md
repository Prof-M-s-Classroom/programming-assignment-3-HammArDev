[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Hamish Arora

## Description
This program does 2 things:
- Represent an undirected, weighted graph 
  - The constructor builds a graph with vertices labeled '0', '1', '2', ... 'n'
  - The addEdge() method creates the corresponding edges in the adjacency matrix
- Return a minimum spanning tree using Prim's Algorithm
  - This greedy algorithm 'builds' a tree by adding the lowest weight cutting edge to the tree
  - Employs a custom minheap to do so

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity                      |
|----------------------|--------------------------------------|
| Insert in MinHeap    | O(log(n))                            |
| Extract Min          | O(1) usually, O(n) my implementation |
| Decrease Key         | O(log(n))                            |
| Prim’s MST Overall   | O((V+E)*log(n))                      |

- Inserting in MinHeap: Inserting into the min heap itself may require the node to be swapped to the top.
                      Since a MinHeap is a complete tree, this means that we'll need at most the height, or log(n) swaps.
- Extract Min: Extracting the minimum itself is O(1). However, in my implementation, I also need to shift all the elements to the left, so it's O(n)
- Decrease Key: Just like inserting, after updating the node, we'll need to upheap, therefore it's O(log(n))
- Prim's MST Overall: Since we process all the vertices and their edges, we have V+E iterations. In each iteration, 
we either insert() or decreaseKey(), which is worst case O(log(n)). However, since the extract min is O(n), The body of the loop
runs O(n)+O(log(n))=O(n) times. Therefore, this algorithm runs O((V+E)*n) overall.
## Assumptions
Your inputted graph is 
- Undirected
- Weighted
- Connected
. In addition, the latest addEdge() edge weight will be counted.
## Test Case Description
Input: The testCase1() & testCase2() function in main.cpp tests the function's adjacency matrix
        and spanning tree output. They work as expected, and if I change the starting vertex, I
        can obtain both possible min spanning trees for testCase1().
## Challenges Faced
- Not properly updating the first edge, leading to a min spanning tree with V-2 edges
- Improperly removing the minimum, resulting in incorrect edges
- Forgetting to upheap after decreasing the key
- Forgetting to swap the vertex, position, and key values when upheaping. Whoops :)
#include <cstdint>
#include <iostream>
#include "graph.h"
#include "math.h"
using namespace std;
void testCase1(){
    Graph g(7);
    g.addEdge(0, 3, 0);
    g.addEdge(0, 1, 8);
    g.addEdge(0, 5, 7);
    g.addEdge(0, 6, 1);
    g.addEdge(1, 5, 1);
    g.addEdge(3, 2, 6);
    g.addEdge(3, 6, 2);
    g.addEdge(2, 5, 7);
    g.addEdge(4, 5, 6);
    g.addEdge(6, 4, 7);
    g.addEdge(2, 6, 7);
    g.addEdge(0, 2, 1);
    cout<<"Test Case 1:\n";
    g.printGraph();
    g.primMST();
    //Two possibilities:
// 0--3
// 0--2
// 0--6
// 0--5 //
// 5--1
// 5--4
//     OR
// 0--3
// 0--2
// 0--6
// 2--5 //
// 5--1
// 5--4
//     Weight: 16
}

void testCase2() {
    Graph t(8);
    t.addEdge(0, 1, 6);
    t.addEdge(1, 6, 5);
    t.addEdge(0, 6, 1);
    t.addEdge(6, 4, 7);
    t.addEdge(6, 5, 6);
    t.addEdge(5, 0, 0);
    t.addEdge(5, 7, 3);
    t.addEdge(7, 3, 6);
    t.addEdge(3, 0, 8);
    t.addEdge(3, 2, 4);
    t.addEdge(2, 4, 5);
    //Expected min-spanning tree:
    // 4--2 5
    // 2--3 4
    // 7--3 6
    // 7--5 3
    // 5--0 0
    // 0--6 1
    // 6--1 5
    // Total: 24
    cout<<"Test case 2\n";
    t.printGraph();
    t.primMST();
}
int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    g.printGraph();
    g.primMST();
    cout<<endl;
    //testCase1();
    testCase2();

    return 0;
}
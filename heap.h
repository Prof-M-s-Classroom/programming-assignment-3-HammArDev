#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
        size = 0;
    }
    ~MinHeap();
    void insert(int newVertex, int origin, int key) {
        heapArray[size]=newVertex;
        position[size]=origin;
        keyArray[size]=key;
        minHeapify(size);
        size++;
    }
    //Returns the edge in the format (end, start, weight)
    int* extractMin() {
        return new int[3]{heapArray[0], position[0], keyArray[0]};
    }
    void decreaseKey(int vertex, int origin, int newKey) {
        int idx=vertexPos(vertex);
        position[idx]=origin;
        keyArray[idx]=newKey;
    }
    bool isInMinHeap(int vertex) {
        for (int i=0; i<size; i++) {
            if (heapArray[i]==vertex)
                return true;
        }
        return false;
    }
    int vertexPos(int vertex) {
        for (int i=0; i<size; i++) {
            if (heapArray[i]==vertex) {
                return i;
            }
        }
        return -1;
    }
    bool isEmpty() {
        if (size==0) {
            return true;
        }
        return false;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    //idx is the position of the newest, inserted vertex
    //or, the size
    void minHeapify(int idx) {
        while (keyArray[idx]<keyArray[(idx-1)/2] && idx>0) {
            int temp = keyArray[idx];
            keyArray[idx]=keyArray[(idx-1)/2];
            keyArray[(idx-1)/2]=temp;
            idx=(idx-1)/2;
        }
    }
};

#endif
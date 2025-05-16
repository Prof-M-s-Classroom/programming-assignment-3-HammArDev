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
    ~MinHeap() {
        delete heapArray;
        delete keyArray;
        delete position;
    }
    void insert(int newVertex, int origin, int key) {
        if (!isInMinHeap(newVertex)) {
            heapArray[size]=newVertex;
            position[size]=origin;
            keyArray[size]=key;
            size++;
            minHeapify(size-1);
        }else {
            int pos = vertexPos(newVertex);
            if (key<keyArray[pos]) {
                decreaseKey(newVertex, origin, key);
            }
        }
    }
    //Returns the edge in the format (end, start, weight)
    int* extractMin() {
        int* ret = new int[3]{heapArray[0], position[0], keyArray[0]};
        heapArray[0]=heapArray[size-1];
        keyArray[0]=keyArray[size-1];
        position[0]=position[size-1];
        size--;
        int temp=0;
        while ((2*temp+1<size&&keyArray[2*temp+1]<keyArray[temp])||(2*temp+2<size&&keyArray[2*temp+2]<keyArray[temp])) {
            if (keyArray[2*temp+1]<keyArray[2*temp+2]) {
                swap(temp, 2*temp+1);
                temp=2*temp+1;
            }else {
                swap(temp, 2*temp+2);
                temp=2*temp+2;
            }

        }
        return ret;
    }
    void decreaseKey(int vertex, int origin, int newKey) {
        int idx=vertexPos(vertex);
        position[idx]=origin;
        keyArray[idx]=newKey;
        minHeapify(idx);
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
    void printheap() {
        for (int i=0; i<size; i++) {
            std::cout<<heapArray[i]<<"--"<<position[i]<<"\t"<<keyArray[i]<<std::endl;
        }
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
            swap(idx, (idx-1)/2);
            idx=(idx-1)/2;
        }
    }
    void swap(int idx1, int idx2) {
        int temp = heapArray[idx1];
        heapArray[idx1]=heapArray[idx2];
        heapArray[idx2]=temp;
        temp = position[idx1];
        position[idx1]=position[idx2];
        position[idx2]=temp;
        temp=keyArray[idx1];
        keyArray[idx1]=keyArray[idx2];
        keyArray[idx2]=temp;
    }
};

#endif
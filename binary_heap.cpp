#include "stdc++.h"

using namespace std;

// #define INT_MAX 2147483647
// #define INT_MIN -2147483648

struct Heap {
    int capacity;
    int size;
    int *array;
};

int parent(int i) {
    return (i - 1)/2;
}

int leftChild(i) {
    return 2*i + 1;
}

int rightChild(i) {
    return 2*i + 2;
}

void insert(Heap *heap, int value) {
    if(heap->size == heap->capacity) {
        heap->capacity = 2*heap->capacity;
        heap->array = (int*) realloc(heap->array, heap->capacity * sizeof(int));
    }
    heap->array[heap->size] = value;
    heap->size++;
    int index = heap->size - 1;
    while(index != 0) {
        int parentIndex = (index - 1) / 2;
        if(heap->array[parentIndex] <= heap->array[index]) {
            break;
        } else {
            int temp = heap->array[parentIndex];
            heap->array[parentIndex] = heap->array[index];
            heap->array[index] = temp;
            index = parentIndex;
        }
    }
}

void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; ++i)
    {
        cout << heap->array[i] << " ";
    }
    cout << endl;
}

int getInteger(string s) {
    int n;
    stringstream ss(s);
    ss >> n;
    return n;
}

int getMinimum(Heap *heap) {
    return heap->array[0];
}

void heapify(Heap *h, int i) {
    int n = h->size - 1;
    // floor is actually not needed, but okay
    while(i <= floor((n-1)/2)) {
        int min = i;
        if(h->array[min] > h->array[2*i + 1]) {
            min = 2*i + 1;
        }
        if(2*i + 2 <= n && h->array[min] > h->array[2*i + 2]) {
            min = 2*i + 2;
        }
        if(min == i) {
            break;
        }
        int temp = h->array[min];
        h->array[min] = h->array[i];
        h->array[i] = temp;
        i = min;
    }
}


int extractMinium(Heap *heap) {
    if(heap->size == 0) {
        cout << "No elements left in heap" << endl;
        return INT_MIN;
    }
    int value = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    heapify(heap, 0); // works like a charm

    // int index = 0;
    // // int childIndex1 = 2*index + 1;
    // // int childIndex2 = 2*index + 2;
    // while(1) {
    //     // find the better version of writing this while loop in the heapify method.
    //     // or you can just replace it with heapify method.
    //     int childIndex1 = 2*index + 1;
    //     int childIndex2 = 2*index + 2;
    //     if(childIndex1 > heap->size - 1) {
    //         break;
    //     }
    //     if(childIndex2 > heap->size - 1) {
    //         if(heap->array[index] > heap->array[childIndex1]) {
    //             int temp = heap->array[index];
    //             heap->array[index] = heap->array[childIndex1];
    //             heap->array[childIndex1] = temp;
    //         }
    //         break;
    //     }
    //     int minIndex;
    //     if(heap->array[childIndex1] > heap->array[childIndex2]) {
    //         minIndex = childIndex2;
    //     } else {
    //         minIndex = childIndex1;
    //     }
    //     if(heap->array[minIndex] < heap->array[index]) {
    //         int temp = heap->array[index];
    //         heap->array[index] = heap->array[minIndex];
    //         heap->array[minIndex] = temp;
    //         index = minIndex;
    //     } else {
    //         break;
    //     }
    // }
    return value;
}

// this makeHeap method correctly finds the index of element that is not the leaf node.
// it first gets the height of the tree. Consider tree looks like this -
//                        *
//
//                *               *
//
//                                  -----
//            *       *       (*)   | * | <= 2
//                                  -----
//        --------------------
//    1=> |*     *  *    *  *|
//        --------------------
// now 1 and 2 are leaf nodes that we want to remove. While the bracketed ones is the node that we want to start
// our heapify algorithm to begin. So we first calculates the numbers of leaf nodes present in 1 (leafNodes1)
// then we calculate number of the leaf nodes present in 2 (leafNodes2).
// After that we calculate index of bracketed node.
// This is an efficient method but little complex

void makeHeap(Heap *h) {
    int n = h->size;
    int height = ceil(log(n + 1)/log(2));
    int leafNodes1 = n - (pow(2, height-1) - 1);
    int leafNodes2 = pow(2, height-2) - ceil(leafNodes1 / 2);
    int index = n - 1 - leafNodes1 - leafNodes2;

    for(int i=index; i>=0; i--) {
        heapify(h, i);
    }
}

// It is a simple algorithm.
// It takes every node, find its parent element and run heapify for it.
// this way, we never run heapify for the leaf nodes, but it has one problem
// since two child has one parent, the heapify method runs two times for a parent node.
// But it is not inefficient because since we have already run heapify first time,
// second time heapify will run in O(1) only. So in total, time complexity will remain same.
void makeHeap2(Heap* h) {
    int n = h->size;
    for(int i = n-1; i>0; i--) {
        int parentIndex = (i - 1) /2;
        heapify(h, parentIndex);
    }
}


int main(int argc, char const *argv[])
{
    Heap *heap = new Heap();
    heap->capacity = 16;
    heap->size = 0;
    heap->array = (int*) malloc(heap->capacity * sizeof(int));
    while(1) {
        cout << "give a number to be inserted in the heap or enter p to print heap" << endl;
        string input;
        cin >> input;
        if(input == "p") {
            printHeap(heap);
            continue;
        }
        if(input == "a") {
            // prefill the array
            int n = 9;
            // int array[] = {-1, 0, 3, 5, 2, 6, 4, 9, 7};
            int array[] = {4, 5, 6, 7, 8, 9 , 0 , 1 , 2};
            // for(int i=0; i<n; i++) {
            //     insert(heap, array[i]);
            // }
            heap->array = array;
            heap->size = n;
            makeHeap2(heap);
            printHeap(heap);
            continue;
        }
        if(input == "e") {
            // extract min
            cout << extractMinium(heap) << endl;
            continue;
        }
        int value = getInteger(input);
        insert(heap, value);

    }
    return 0;
}

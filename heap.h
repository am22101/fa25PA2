//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        int temp = data[0];
        size--;
        data[size] = temp;
        downheap(0, weightArr);
        return temp;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parentPos = (pos - 1) / 2;
            int childIndex = data[pos];
            int parentIndex = data[parentPos];

            if (weightArr[childIndex] < weightArr[parentIndex]) {
                int temp = data[pos];
                data[pos] = data[parentPos];
                data[parentPos] = temp;
                pos = parentPos;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        while (pos * 2 + 1 < size) {
            int leftChildPos = pos * 2 + 1;
            int rightChildPos = pos * 2 + 2;
            int childToSwap = leftChildPos;

            if (rightChildPos < size) {
                int leftChildIndex = data[leftChildPos];
                int rightChildIndex = data[rightChildPos];
                if (weightArr[rightChildIndex] < weightArr[leftChildIndex]) {
                    childToSwap = data[rightChildPos];
                }
            }

            int childIndex = data[childToSwap];
            int parentIndex = data[pos];

            if (weightArr[childIndex] < weightArr[parentIndex]) {
                int temp = data[pos];
                data[pos] = data[childToSwap];
                data[childToSwap] = temp;
                pos = childToSwap;
            } else {
                break;
            }
        }
    }
};

#endif
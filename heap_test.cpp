#include "heap.h"
#include <iostream>
#include <functional>

void testMinHeap() {
    Heap<int> minHeap(2); // Default is min-heap
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(1);
    
    std::cout << "Min-Heap Output: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;
}

void testMaxHeap() {
    Heap<int, std::greater<int>> maxHeap(2); // Max heap
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    maxHeap.push(1);
    
    std::cout << "Max-Heap Output: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing Min-Heap:" << std::endl;
    testMinHeap();
    
    std::cout << "\nTesting Max-Heap:" << std::endl;
    testMaxHeap();
    
    return 0;
}
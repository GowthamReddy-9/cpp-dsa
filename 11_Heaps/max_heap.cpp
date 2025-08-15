#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void pushMax(int k, vector<int>& heap) {
    heap.push_back(k);
    int ind = heap.size() - 1;
    while (ind > 0) {
        int parent = (ind - 1) / 2;
        if (heap[parent] < heap[ind]) { // flipped comparison
            swap(heap[parent], heap[ind]);
            ind = parent;
        } else break;
    }
}

void popMax(vector<int>& heap) {
    if (heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();

    int n = heap.size();
    int ind = 0;
    while (true) {
        int largest = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < n && heap[left] > heap[largest]) largest = left;  // flipped
        if (right < n && heap[right] > heap[largest]) largest = right; // flipped

        if (largest != ind) {
            swap(heap[largest], heap[ind]);
            ind = largest;
        } else break;
    }
}

int topMax(const vector<int>& heap) {
    if (heap.empty()) {
        cout << "Heap is empty\n";
        return INT_MIN; // sentinel for max-heap
    }
    return heap[0];
}

int main() {
    vector<int> heap;
    pushMax(15, heap);
    pushMax(7, heap);
    pushMax(9, heap);
    pushMax(12, heap);
    pushMax(1, heap);
    pushMax(3, heap);
    pushMax(7, heap);

    cout << "Top element: " << topMax(heap) << "\n"; // 15
    popMax(heap);
    cout << "Top after pop: " << topMax(heap) << "\n"; // 12
}
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq; // max heap

    pq.push(15);
    pq.push(7);
    pq.push(9);
    pq.push(12);
    pq.push(1);
    pq.push(3);
    pq.push(7);

    cout << "Top element: " << pq.top() << "\n"; // 15
    pq.pop(); // removes largest
    cout << "Top after pop: " << pq.top() << "\n"; // 12
}
*/

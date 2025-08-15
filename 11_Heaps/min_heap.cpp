#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void pushMin(int k, vector<int>& heap) {
    heap.push_back(k);
    int ind = heap.size() - 1;
    while (ind > 0) {
        int parent = (ind - 1) / 2;
        if (heap[parent] > heap[ind]) {
            swap(heap[parent], heap[ind]);
            ind = parent;
        } else break;
    }
}

void popMin(vector<int>& heap) {
    if (heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();

    int n = heap.size();
    int ind = 0;
    while (true) {
        int smallest = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < n && heap[left] < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;

        if (smallest != ind) {
            swap(heap[smallest], heap[ind]);
            ind = smallest;
        } else break;
    }
}

int top(const vector<int>& heap) {
    if (heap.empty()) {
        cout << "Heap is empty\n";
        return INT_MAX; // sentinel
    }
    return heap[0];
}

int main() {
    vector<int> heap;
    pushMin(15, heap);
    pushMin(7, heap);
    pushMin(9, heap);
    pushMin(12, heap);
    pushMin(1, heap);
    pushMin(3, heap);
    pushMin(7, heap);

    cout << "Top element: " << top(heap) << "\n"; // 1
    popMin(heap);
    cout << "Top after pop: " << top(heap) << "\n"; // 3
}
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    pq.push(15);
    pq.push(7);
    pq.push(9);
    pq.push(12);
    pq.push(1);
    pq.push(3);
    pq.push(7);

    cout << "Top element: " << pq.top() << "\n"; // 1
    pq.pop(); // removes smallest
    cout << "Top after pop: " << pq.top() << "\n"; // 3
}
*/

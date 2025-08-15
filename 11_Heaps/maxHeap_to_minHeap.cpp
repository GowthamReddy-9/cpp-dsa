#include <bits/stdc++.h>
using namespace std;

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void convertMaxToMinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = (n - 2) / 2; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

int main() {
    vector<int> maxHeap = {9, 7, 6, 5, 3, 2, 1};
    cout << "Original Max-Heap: ";
    for (int x : maxHeap) cout << x << " ";
    cout << "\n";

    convertMaxToMinHeap(maxHeap);

    cout << "Converted Min-Heap: ";
    for (int x : maxHeap) cout << x << " ";
    cout << "\n";
    return 0;
}


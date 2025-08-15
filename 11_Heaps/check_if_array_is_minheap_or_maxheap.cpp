#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] > arr[left]) return false;
        if (right < n && arr[i] > arr[right]) return false;
    }
    return true;
}

bool isMaxHeap(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) return false;
        if (right < n && arr[i] < arr[right]) return false;
    }
    return true;
}

int main() {
    vector<int> minHeapTrue = {1, 3, 5, 7, 9, 11};
    vector<int> minHeapFalse = {3, 1, 5, 7, 9, 11};
    vector<int> maxHeapTrue = {100, 50, 90, 30, 40, 80};
    vector<int> maxHeapFalse = {50, 100, 90, 30, 40, 80};

    cout << "Min-Heap True: " << (isMinHeap(minHeapTrue) ? "Yes" : "No") << '\n';
    cout << "Min-Heap False: " << (isMinHeap(minHeapFalse) ? "Yes" : "No") << '\n';
    cout << "Max-Heap True: " << (isMaxHeap(maxHeapTrue) ? "Yes" : "No") << '\n';
    cout << "Max-Heap False: " << (isMaxHeap(maxHeapFalse) ? "Yes" : "No") << '\n';
}


#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[minIndex] > arr[j]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr1 = {6, 18, 5, 8, 9, 2};
    vector<int> arr2 = {12, 9, 5, 23, 3};
    vector<int> arr3 = {5, 16, 9, 1, 3, 0};

    insertion_sort(arr1);
    bubble_sort(arr2);
    selection_sort(arr3);

    for (auto x : arr1) cout << x << " ";
    cout << endl;
    for (auto x : arr2) cout << x << " ";
    cout << endl;
    for (auto x : arr3) cout << x << " ";
    cout << endl;
}


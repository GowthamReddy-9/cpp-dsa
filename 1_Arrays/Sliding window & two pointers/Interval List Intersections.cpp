// LeetCode: https://leetcode.com/problems/interval-list-intersections/
// Problem: Interval List Intersections
// Concept: Two Pointers on Two Interval Lists

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> result;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        int low = max(A[i][0], B[j][0]);
        int high = min(A[i][1], B[j][1]);

        if (low <= high) {
            result.push_back({low, high});
        }

        // Move the interval with the smaller end
        if (A[i][1] < B[j][1]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> res = intervalIntersection(A, B);

    cout << "Overlapping intervals:\n";
    for (auto& v : res) {
        cout << "[" << v[0] << "," << v[1] << "]\n";
    }

    return 0;
}


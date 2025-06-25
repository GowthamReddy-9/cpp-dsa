// LeetCode: https://leetcode.com/problems/magnetic-force-between-two-balls/
// Problem: Magnetic Force Between Two Balls (Medium/Hard)
// Concept: Binary Search on Answer (Minimum Distance)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceBalls(vector<int>& positions, int m, int minDist) {
    int count = 1; // Place first ball at the first position
    int lastPos = positions[0];

    for (int i = 1; i < positions.size(); i++) {
        if (positions[i] - lastPos >= minDist) {
            count++;
            lastPos = positions[i];
            if (count == m) return true;
        }
    }

    return false;
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());

    int l = 1;
    int r = position.back() - position.front();
    int ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (canPlaceBalls(position, m, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;

    cout << "Maximum Minimum Distance: " << maxDistance(position, m) << endl;
    return 0;
}



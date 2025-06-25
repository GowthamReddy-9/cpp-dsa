// LeetCode: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Problem: Maximum Points You Can Obtain from Cards (Medium)
// Concept: Sliding Window (Prefix-Suffix Window)

#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += cardPoints[i];
    }

    if (k == cardPoints.size()) return sum;

    int ans = sum;
    int j = k - 1;

    for (int i = cardPoints.size() - 1; i >= cardPoints.size() - k; i--) {
        sum = sum - cardPoints[j--] + cardPoints[i];
        if (sum > ans) {
            ans = sum;
        }
    }

    return ans;
}

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << "Maximum Score: " << maxScore(cardPoints, k) << endl;
    return 0;
}


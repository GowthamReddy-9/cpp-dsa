// LeetCode: https://leetcode.com/problems/fruit-into-baskets/
// Problem: Fruit Into Baskets (Medium)
// Concept: Sliding Window (Variable Size), Map for Frequency Tracking

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int totalFruit(vector<int>& fruits) {
    map<int, int> freq;
    int l = 0, r = 0;
    int ans = 0;

    while (r < fruits.size()) {
        freq[fruits[r]]++;

        while (freq.size() > 2) {
            freq[fruits[l]]--;
            if (freq[fruits[l]] == 0) {
                freq.erase(fruits[l]);
            }
            l++;
        }

        ans = max(ans, r - l + 1);
        r++;
    }

    return ans;
}

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3};
    cout << "Max fruits that can be collected: " << totalFruit(fruits) << endl;
    return 0;
}


// LeetCode: https://leetcode.com/problems/boats-to-save-people/
// Problem: Boats to Save People (Medium)
// Concept: Greedy + Two Pointers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    if (people.size() <= 1) return people.size();
    
    sort(people.begin(), people.end());
    int l = 0, r = people.size() - 1;
    int boats = 0;

    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l++;  // pair lightest with heaviest
        }
        r--;      // heavy person always boards
        boats++;   // one boat used
    }

    return boats;
}

int main() {
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    cout << "Minimum boats needed: " << numRescueBoats(people, limit) << endl;
    return 0;
}


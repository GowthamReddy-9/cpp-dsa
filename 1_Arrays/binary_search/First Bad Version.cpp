// Problem: https://leetcode.com/problems/first-bad-version/
#include <iostream>
using namespace std;

// MOCK API FUNCTION
bool isBadVersion(int version) {
    int firstBad = 4; // Simulate that version 4 is the first bad one (you can change it)
    return version >= firstBad;
}

// Function to find first bad version
int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (isBadVersion(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int n;
    cout << "Enter total number of versions: ";
    cin >> n;

    int result = firstBadVersion(n);
    cout << "First bad version is: " << result << endl;
    return 0;
}


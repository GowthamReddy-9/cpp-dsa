#include <iostream>
#include <vector>
using namespace std;

bool canShip(const vector<int>& weights, int D, int capacity) {
    int days = 1, current = 0;
    for (int w : weights) {
        if (current + w > capacity) {
            days++;
            current = 0;
        }
        current += w;
    }
    return days <= D;
}

int shipWithinDays(vector<int>& weights, int D) {
    int low = *max(weights.begin(), weights.end());
    int high = 0;
    for (int w : weights) high += w;

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canShip(weights, D, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> weights = {1, 2, 3, 1, 1};
    int days = 4;
    cout << "Minimum Capacity: " << shipWithinDays(weights, days) << endl;
    return 0;
}


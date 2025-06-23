#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool canEatAll(const vector<int>& piles, int h, int speed) {
    int hours = 0;
    for (int pile : piles) {
        hours += ceil((double)pile / speed);
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max(piles.begin(), piles.end()-1), result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canEatAll(piles, h, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Min Eating Speed: " << minEatingSpeed(piles, h) << endl;
    return 0;
}


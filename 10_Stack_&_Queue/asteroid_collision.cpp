#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a : asteroids) {
            bool alive = true;
            while (alive && a < 0 && !st.empty() && st.back() > 0) {
                if (abs(st.back()) < abs(a)) st.pop_back();
                else if (abs(st.back()) == abs(a)) { st.pop_back(); alive = false; }
                else alive = false;
            }
            if (alive) st.push_back(a);
        }
        return st;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids = {5, 10, -5};
    vector<int> res = sol.asteroidCollision(asteroids);
    for (int x : res) cout << x << " ";
}


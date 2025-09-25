#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value{
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int sum = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && value[s[i]] < value[s[i + 1]])
                sum -= value[s[i]];
            else
                sum += value[s[i]];
        }

        return sum;
    }
};

int main() {
    Solution solution;
    vector<string> romans{"LIX", "LVIII", "MCMXCIV", "III"};
    for (const auto& it : romans) {
        cout << it << " : " << solution.romanToInt(it) << endl;
    }
    return 0;
}


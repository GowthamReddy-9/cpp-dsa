#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;  // skip leading spaces

        if (i == n) return 0;

        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        long long sum = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            sum = sum * 10 + digit;
            i++;
        }

        return sign * sum;
    }
};

int main() {
    Solution solution;
    vector<string> testcases = {
        "42", "   -42", "4193 with words", "words and 987",
        "-91283472332", "+123", "00000123", "   +0 123", "", "   ", "+", "-",
        "2147483647", "2147483648", "-2147483648", "-2147483649"
    };

    for (const auto& str : testcases) {
        cout << "\"" << str << "\" ? " << solution.myAtoi(str) << endl;
    }

    return 0;
}


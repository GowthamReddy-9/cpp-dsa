#include <bits/stdc++.h>
using namespace std;
void reverseWords(string& s) {
    int n = s.size();
    // Step 1: Remove extra spaces in-place
    int i = 0;  // slow pointer
    bool spaceFound = true;
    for (int j = 0; j < n; ++j) {
        if (s[j] != ' ') {
            if (!spaceFound) s[i++] = ' ';
            spaceFound = true;
            while (j < n && s[j] != ' ') s[i++] = s[j++];
        }
        spaceFound = false;
    }
    s.resize(i);
    if (!s.empty() && s.back() == ' ') s.pop_back();
    // Step 2: Reverse entire string
    reverse(s.begin(), s.end());
    // Step 3: Reverse each word
    int start = 0;
    for (int end = 0; end <= s.size(); ++end) {
        if (end == s.size() || s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
}
int main() {
    string s = "  the    sky is  blue  ";
    reverseWords(s);
    cout << s << endl;  // Output: "blue is sky the"
}class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Trim and collapse spaces
        int i = 0, end = s.size() - 1;
        while (i <= end && s[i] == ' ') i++;
        while (end >= i && s[end] == ' ') end--;
        s = s.substr(i, end - i + 1);

        // Collapse multiple spaces to one
        i = 0;
        for (int j = 0; j < s.size(); j++) {
            while (j < s.size() && s[j] != ' ')
                s[i++] = s[j++];
            s[i++] = ' ';
            while (j < s.size() && s[j] == ' ')
                j++;
            j--;
        }
        s.resize(i - 1); // remove trailing space

        // Step 2: Reverse full string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word
        i = 0;
        for (int j = 0; j <= s.size(); j++) {
            if (j == s.size() || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }

        return s;
    }
};

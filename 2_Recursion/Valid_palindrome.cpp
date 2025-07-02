#include <iostream>
#include <string>
using namespace std;

// Recursive function to check if a string is palindrome
bool isPalindrome(string &s, int left, int right) {
    if (left >= right) return true;
    if (s[left] != s[right]) return false;
    return isPalindrome(s, left + 1, right - 1);
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    if (isPalindrome(s, 0, s.length() - 1)) {
        cout << "The string is a palindrome (recursively checked)." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }

    return 0;
}


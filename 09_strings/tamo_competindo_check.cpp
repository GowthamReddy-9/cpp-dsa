#include <iostream>
#include <string>
using namespace std;
// link to problem statement-->https://codeforces.com/gym/105962/problem/B
bool isPossibleMatch(int K, const string& S) {
    string target = "tamocompetindo";
    int len = target.size();

    for (int i = 0; i + len <= S.size(); ++i) {
        int mismatches = 0;
        for (int j = 0; j < len; ++j) {
            if (S[i + j] != target[j]) {
                mismatches++;
                if (mismatches > K) break;
            }
        }
        if (mismatches <= K) return true;
    }
    return false;
}

int main() {
    int K;
    string S;
    cin >> K >> S;

    if (isPossibleMatch(K, S)) cout << "SIM\n";
    else cout << "NAO\n";

    return 0;
}


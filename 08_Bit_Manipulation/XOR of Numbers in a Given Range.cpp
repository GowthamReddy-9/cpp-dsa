#include <bits/stdc++.h>
using namespace std;

int xor_upto(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int Ranged_xor(int l, int r) {
    return xor_upto(r) ^ xor_upto(l - 1);
}

int main() {
    int result = Ranged_xor(8, 12);  // 8^9^10^11^12 = 12
    cout << result << endl;
    return 0;
}


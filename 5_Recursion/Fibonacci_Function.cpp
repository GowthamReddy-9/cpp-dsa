/*
    LeetCode Problem: https://leetcode.com/problems/fibonacci-number/
    Problem #509: Fibonacci Number

    Description:
    Compute the nth Fibonacci number using simple recursion.
    F(0) = 0, F(1) = 1
    F(n) = F(n - 1) + F(n - 2) for n > 1
*/

#include <iostream>
using namespace std;

// Recursive Fibonacci function
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}


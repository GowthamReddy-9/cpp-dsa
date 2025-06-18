#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;       // Pointer to int
    int** pp = &p;     // Pointer to pointer

    cout << "Value of x: " << x << endl;
    cout << "Using *p: " << *p << endl;
    cout << "Using **pp: " << **pp << endl;

    return 0;
}


#include <iostream>
using namespace std;
// Function for Function Pointer Demo
void greet() {
    cout << "[5] Function Pointer: Hello from a function!" << endl;
}
int main() {
    cout << "\n--- Pointer Types in C++ Demonstration ---\n" << endl;
    // 1. Null Pointer
    int* nullPtr = NULL;
    cout << "[1] Null Pointer: nullPtr = " << nullPtr << endl;
    // 2. Dangling Pointer
    int* danglingPtr;
    {
        int temp = 42;
        danglingPtr = &temp;
        cout << "[2] Dangling Pointer (valid here): " << *danglingPtr << endl;
        temp;
    }
    // temp is out of scope; danglingPtr is now invalid
    
    // 3. Void Pointer
    int x = 99;
    void* voidPtr = &x;
    cout << "[3] Void Pointer: pointing to x = " << *((int*)voidPtr) << endl;

    // 4. Wild Pointer
    int* wildPtr;
    // wildPtr is uninitialized ? wild pointer (DON'T dereference)
    cout << "[4] Wild Pointer: (Uninitialized — never dereference!)" << endl;

    // 5. Function Pointer
    void (*funcPtr)() = greet;
    funcPtr();  // Calling the function via pointer

	cout << "\n--- End of Pointer Demonstration ---" << endl;
    return 0;
}


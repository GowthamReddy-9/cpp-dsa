#include<iostream>
using namespace std;

int main()
{
    int* ptr = new int;
    *ptr = 5;
    int n = *ptr;

    delete ptr;  // memory freed

    // Don't access ptr here – it's a dangling pointer now.
    // cout << "While Dangling: " << *ptr << endl;

    ptr = NULL;  // Good practice to avoid dangling pointer

    // ? Don't dereference NULL pointer!
    // cout << "After changing to null: " << *ptr << endl;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = NULL;

    return 0;
}


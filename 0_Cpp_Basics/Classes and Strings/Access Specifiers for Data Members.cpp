#include <iostream>
using namespace std;

class Base {
private:
    int privateVar;

protected:
    int protectedVar;

public:
    int publicVar;

    // Constructor to initialize all variables
    Base() {
        privateVar = 1;
        protectedVar = 2;  
        publicVar = 3;
    }

    // Public method to access privateVar (outside class can't access it directly)
    void showPrivateVar() {
        cout << "Private Variable (inside Base): " << privateVar << endl;
    }

    // Public method to access protectedVar (also hidden from outside)
    void showProtectedVar() {
        cout << "Protected Variable (inside Base): " << protectedVar << endl;
    }
};

class Derived : public Base {
public:
    void accessBaseMembers() {
        // privateVar is NOT accessible here --> Error if uncommented
        // cout << privateVar << endl;

        // protectedVar is accessible in derived class
        cout << "Protected Variable (from Derived): " << protectedVar << endl;

        // publicVar is accessible
        cout << "Public Variable (from Derived): " << publicVar << endl;
    }
};

int main() {
    Base objBase;
    Derived objDerived;

    cout << "Accessing from Base class object:" << endl;
    // cout << objBase.privateVar << endl;     // can't access -->Error if Uncommented
    // cout << objBase.protectedVar << endl;   //cant't access
    cout << "Public Variable (from Base): " << objBase.publicVar << endl;

    objBase.showPrivateVar();     //  Accessing private using public method
    objBase.showProtectedVar();   //  Accessing protected using public method

    cout << "\nAccessing from Derived class object:" << endl;
    objDerived.accessBaseMembers();

    return 0;
}


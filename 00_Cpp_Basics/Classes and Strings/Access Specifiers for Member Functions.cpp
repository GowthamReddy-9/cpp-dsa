#include <iostream>
using namespace std;

class Base {
private:
    void privateFunc() {
        cout << "Private Function of Base" << endl;
    }

protected:
    void protectedFunc() {
        cout << "Protected Function of Base" << endl;
    }

public:
    void publicFunc() {
        cout << "Public Function of Base" << endl;
        privateFunc();   //  Allowed: private method accessed inside class
        protectedFunc(); //  Allowed: protected method accessed inside class
    }
};

class Derived : public Base {
public:
    void accessFunctions() {
        // privateFunc();    // Error: private function not accessible in derived class
        protectedFunc();    //  OK: protected function accessible
        publicFunc();       // OK: public function accessible
    }
};

int main() {
    Base obj;
    Derived d;

    obj.publicFunc();       //   OK
    // obj.protectedFunc(); //  Error: protected function not accessible
    // obj.privateFunc();   //  Error: private function not accessible

    d.accessFunctions();    //  OK: uses inherited public and protected methods

    return 0;
}


#include <iostream>
using namespace std;

class Base {
public:
     void show() { // if we add virtual derived class show will excutes
        cout << "Base class show function" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show function" << endl;
    }
};

int main() {
    Base* ptr;
    Derived obj;
    ptr = &obj;

    ptr->show();   // Calls Base class function 
    return 0;
}
//function overriding
#include<iostream>
using namespace std;

class Parent{
    public:
     void show(){
        cout<<"parent class..\n";
     }
};
class Child :public Parent{
    public:
      void show(){
        cout<< "child class...\n";
      }
};


int main(){
    Child child1;
    child1.show();//child class....(excutes child class method ( function overriding ))
    return 0;

}
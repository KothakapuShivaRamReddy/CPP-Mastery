//virtual  functions

#include<iostream>
using namespace std;

class Parent{
    public:
     void show(){
        cout<<"parent class..\n";
     }
     virtual void hello(){
        cout<<"parent class hello...\n";//virtual functions must be defined in the child class
     }
};
class Child :public Parent{
    public:
      void show(){
        cout<< "child class...\n";
      }
      void hello(){
        cout<<"child class hello...\n";
      }
};


int main(){
    Child child1;
    Parent *ptr; //obj of parent is pointer
    ptr=&child1;// assiging child1 address to pointer //runtime binding
    ptr->hello();//virtual function
    return 0;

}
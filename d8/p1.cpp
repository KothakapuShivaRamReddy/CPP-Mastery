#include<iostream>
using namespace std;
 
class A{
    public:
       A(){
         cout<<"A constuctor"<<endl;
       }
       ~A(){
        cout<<"A destructor"<<endl;

       }
};
class B:public A{
    public:
       B(){
        cout<<"B constructor"<<endl;

       }
       ~B(){
          cout<<"B destructor"<<endl;
       }
};


int main(){
    B b;

    return 0;

}
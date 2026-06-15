// inheritance
//mode of inheritance 
//example of single inheritance

#include<iostream>
using namespace std;

class  Animal{
    public:
       void eat(){
        cout<<"eats"<<endl;

       }
       void breathe(){
        cout<<"breathe"<<endl;
       }
};
class Fish:protected Animal{
    public:
       int fins;
       void swim(){
        eat(); //inside derived class is possible
        cout<<"fish can swim"<<endl;
       }
};



int main(){
    Fish f;
    f.swim();
    //not possible because mode of inheriting parent is protected it can accesed in derived class only
    // f.breathe();
    // f.eat();
    return 0;

}
      
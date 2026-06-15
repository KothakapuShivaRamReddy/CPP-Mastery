#include<iostream>
using namespace std;

class  Animal{
    public:
       void eat(){
        cout<<"animal can eat"<<endl;

       }
       void breathe(){
        cout<<"Animal can breathe"<<endl;
       }
};
class Fish:public Animal{
    public:
       int fins;
       void swim(){
        cout<<"fish can swim"<<endl;
       }
};



int main(){
    Fish f;
    f.swim();
    f.eat();
    return 0;

}
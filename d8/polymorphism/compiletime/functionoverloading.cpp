
//function overloading

#include<iostream>
using namespace std;
class Print{
    public:
      void show(int x){
        cout<<"int:"<< x<<endl;

      }
      void show(string str){
        cout<<"String:"<<str<<endl;
      }
};

int main(){
    Print ob1;
    ob1.show(20);//
    ob1.show("shiva");//
    return 0;
}
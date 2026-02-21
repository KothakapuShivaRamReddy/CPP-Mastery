#include<iostream>
using namespace std;

class Example{
    public:
       Example(){
        cout<<"this is constructor."<<endl;

       }
       ~Example(){      //not required this was done automatically by the compiler {deallocating the memory of object}
        cout<<"this is destructor";
       }
};

int main(){
    Example e;
    

    return 0;

}
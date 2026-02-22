#include<iostream>
using namespace std;
class Example{
    public:
    //   int x=0;
    static int x;
};

 int Example::x=0;

int main(){
    Example e1;
    Example e2;
    Example e3;

    cout<<e1.x++<<endl;
    cout<<e2.x++<<endl;
    cout<<e3.x++<<endl;
    
    return 0;

}   
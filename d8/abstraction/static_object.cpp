//static_object
#include<iostream>
using namespace std;
class Example{
    public:
      Example(){
        cout<<"constructor..\n";
      }
      ~Example(){
        cout<<"destructor..\n";
      }
};



int main(){
  
    int a=0;
    if(a==0){
        Example e;
        // static Example e;
    }
    cout<<"code ending..\n";
    return 0;

}  
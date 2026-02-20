#include<iostream>
#define X 25  //macros (no memory space needed)
using namespace std;
int main(){
    const int Y=35; //constants (stored ata single memory space)
   cout<<Y<<endl;//at runtime
   cout<<X<<endl;//befor runtime

}
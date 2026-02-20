#include<iostream> 
using namespace std;
void pointer(int *ptr){
    cout<<ptr<<endl;
    *ptr=*ptr+1;
    cout<<*ptr;
}
int main(){
    int a=10;
    pointer(&a);

    return 0;
}
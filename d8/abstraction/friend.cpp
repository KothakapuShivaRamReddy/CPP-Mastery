//friend fnx andfrnd class]
#include<iostream>
using namespace std;
   class A{
       string secret = "secret data";

       friend class B;
       friend void revealSecret(A &obj);};
   class B {//becomes a friend class of A
           public:
           void showSecret (A &obj) {
                cout <<obj.secret << endl;
          }
};
void revealSecret (A &obj) {
    cout << obj.secret << endl;
}

int main(){
    A al;
    B bl;
     bl.showSecret(al);
     revealSecret(al);
    return 0;
}
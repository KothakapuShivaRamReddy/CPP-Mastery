#include<iostream>
#include<string.h>
using namespace std;

class Car {
   public:
      string name;
      string color;
      int *mileage;
      Car(string name, string color) {
             this->name = name;
             this->color = color;
             mileage = new int;
             *mileage = 12;
      }// by(Default) shallow copy was done without custom copy method

    //   Car(Car &original){
    //       cout << "copying original to new..\n";
    //       name = original.name;
    //       color=original.color;
    //       mileage=original.mileage;}
    };

int main(){
      Car c1("maruti 800", "white");
      Car c2(c1);
      cout << c2.name << endl;
     cout << c2.color << endl;
      cout << *(c2.mileage) << endl;
      *c2.mileage=10;          //for two objects the reference is same one changes another changes 
      cout << *c1.mileage << endl;
      cout << *c2.mileage << endl;
      //checking address
      cout << c1.mileage << endl;  //same address we get reference is same shallow copy
      
      cout << c2.mileage << endl;

    return 0;

}
// maruti 800
// white
// 12
// 10
// 10
// 0x1141bd8     
// 0x1141bd8
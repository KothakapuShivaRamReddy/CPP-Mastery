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
      }
      //custom copy constructor  needed when we need deep copy

      Car(Car &original){
          cout << "copying original to new..\n";
          name = original.name;
          color=original.color;
          mileage=new int;
          *mileage=*original.mileage;}
    };

int main(){
      Car c1("maruti 800", "white");
      Car c2(c1);
      cout << c2.name << endl;
     cout << c2.color << endl;
      cout << *(c2.mileage) << endl;
      *c2.mileage=10;          
      cout << *c1.mileage << endl;//another memory is allocated in an heap (deep copy)
      //checking address
      cout << c1.mileage << endl;
      cout << c2.mileage << endl;
    return 0;

}
// copying original to new..
// maruti 800
// white
// 12
// 12
// 0x8d1bd8
// 0x8d1be8
//
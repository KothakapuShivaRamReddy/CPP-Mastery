#include<iostream> 
#include<string.h>
using namespace std;

class Car{
   string name;//default private
   string color;
   public:
       Car(string name,string color){
          cout<<"called constructor"<<endl;
           this->name=name;
           this->color=color;

       }
       //getter
       string getName(){//to acess the private acess modifier in the main using getter
         return name;

       }

};


int main(){
  Car c1("dodge","red");
  cout<<c1.getName();


    return 0;

}
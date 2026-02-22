#include<iostream>
using namespace std;

class Shape{
    public:
      virtual void draw()=0;//abstract fnx,pure virtual fnx
};
class Square:public Shape{
    public:
      void draw(){
        cout<<"drawing square\n";

      }
};
class Circle:public Shape{
    public:
      void draw(){
        cout<<"drawing circle\n";
        
      }
};

int main(){
    Square squr;
    squr.draw();
    Circle cir;
    cir.draw();

    // Shape s;    //error
    // s.draw();
    return 0;
}
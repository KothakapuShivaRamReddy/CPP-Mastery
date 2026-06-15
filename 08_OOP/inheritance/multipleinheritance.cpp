//multiple inheritance


#include<iostream>
#include<string.h>
using namespace std;

class Teacher {
  public:
      int salary;
      string subject;
};
class Student {
    public:
      int rollno;
      float cgpa;
};
class TA: public Teacher, public Student{
    public:
    string name;
};

int main(){
    TA tal;
   tal.name="shiva";
   tal.subject="C++";
   tal.cgpa=9.27;
   cout<< tal.name << endl;
   cout << tal.subject<< endl;
  cout << tal.cgpa<<endl;

    return 0;
}
#include<iostream>
#include<queue>
using namespace std;

class Student{
public:
    string name;
    int marks;
    Student(string name,int marks){
        this->name=name;
        this->marks=marks;
    }

    bool operator<(const Student &s) const{
        return this->marks<s.marks;//for max heap
        //return this->marks>s.marks;//for min heap
    }
};

int main(){
    priority_queue<Student> pq;
    pq.push(Student("A",90));
    pq.push(Student("B",80));
    pq.push(Student("C",95));
    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
//   C 95
//   A 90
//   B 80


    return 0;
}
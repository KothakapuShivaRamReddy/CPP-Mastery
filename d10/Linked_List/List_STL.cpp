#include<iostream>
#include<list>//linked list is already implemented in stl and we can use it by including list header file
#include<iterator>//for using iterator in stl we have to include iterator header file
using namespace std;


void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){//begin() returns the iterator pointing to the first element of the list and end() returns the iterator pointing to the past-the-end element of the list
        cout<<(*itr)<<"->";

    }
    cout<<"NULL"<<endl;
}
int main(){
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(3);
    ll.push_back(4);

    // list<int>::iterator itr;
    // for(itr=ll.begin();itr!=ll.end();itr++){
    //     cout<<(*itr)<<"->";

    // }
    cout<<"Size:"<<ll.size()<<endl;//4
    cout<<"Head:"<<ll.front()<<endl;//1
    cout<<"Tail:"<<ll.back()<<endl;//4
    
    printList(ll);//1->2->3->4->NULL

    ll.pop_front();
    ll.pop_back();
     printList(ll);//2->3->NULL



    return 0;

}
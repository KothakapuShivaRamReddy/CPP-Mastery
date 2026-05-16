#include<iostream>
using namespace std;
// template<class T>
class Node{
  public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }

};
class Queue{
   
       Node* head;
       Node* tail;
    public:
       Queue(){
        head=tail=NULL;
       }
      //push_back
       void push(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;

       }
       //pop_back
       void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
           }
         Node *temp=head;
         head=head->next;
         if(head==NULL){
            tail=NULL;
         }
         delete temp;

       }
       int front(){
           if(empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
           }else{
             return head->data;
       }
     }
     bool empty(){
        return head==NULL;
     }
           

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<<q.front()<<" ";//1 2 3
        q.pop();
    }

}
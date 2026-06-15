#include<iostream>
using namespace std;

class Node{
    public:
      int data;
      Node* next;

  
      Node(int val){
         data=val;
         next=NULL;

      }
    //   ~Node(){
    //     // cout<<"~Node"<<data<<endl;
    //     if(next!=NULL){
    //         delete next;
    //         // cout<<"~node"<<data<<endl;
    //         next=NULL;
    //     }
    //   }

};
class List{
    public://made public we want to access outside the class head is used in the printLIst which is outside fnx;
      Node* head;
      Node* tail;

    // public:
       List(){
         head=NULL;
         tail=NULL; 
       }
    //    ~List(){
    //     //  cout<<"~List"<<endl;
    //      if(head!=NULL){
    //         delete head;
    //         head=NULL;
    //      }
         
    //    }

       void push_front(int val){
           Node* newNode=new Node(val);//dynamic allocation that is why we are using new keyword that was not deleted when the out of the function and we can use it in the main function also
           //Node* newNode(val);//static allocation that is why we are not using new keyword that was deleted when the out of the function and we can not use it in the main function also
           if(head==NULL){
             head=tail=newNode;
           }else{
             newNode->next=head;
             head=newNode;
           }
        }
         void push_back(int val){
            Node* newNode=new Node(val);
            if(head==NULL){
                head=tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        } };
void printList(Node *head){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL\n";
}

bool isCycle(Node *head){
    Node *slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"Cycle exists"<<endl;  
            return true;
        }

    }
    cout<<"Cycle not exists"<<endl;
    return false;
}

int main(){
    List ll;
    
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next=ll.head;
    isCycle(ll.head);
    //ll.tail->next=NULL;//if uses the distructors
    // printList(ll.head);//loop will prints infinite
    return 0;
}
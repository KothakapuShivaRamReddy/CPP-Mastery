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

Node* merge(Node* left,Node* right){
    List ans;
    Node* i=left;
    Node* j=right;
    while(i!=NULL && j!=NULL){
        if(i->data<=j->data){
            ans.push_back(i->data);
            i=i->next;
        }else{
             ans.push_back(j->data);
            j=j->next;
        }
    }
    while(i!=NULL){
        ans.push_back(i->data);
        i=i->next;
    }
    while(j!=NULL){
        ans.push_back(j->data);
        j=j->next;
    }
    return ans.head;
}




Node* splitAtMid(Node* head){
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    return slow;//slow=righthead
}


Node*  mergesort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* righthead=splitAtMid(head);

    //left head
    Node* left=mergesort(head);
    //right head
    Node* right=mergesort(righthead);
    return merge(left,right);//head ofsorted ll
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* next=NULL;
    Node*prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    return prev;
}

Node* ZigZag(Node* head){

      Node* righthead=splitAtMid(head);

     Node* rightHeadRev= reverse(righthead);
     //alternative merging:1st Head=head;2nd head=rightHeadRev
     Node* left=head;
     Node* right=rightHeadRev;
     Node* tail=right;
     while(left!=NULL && right!=NULL){
        Node* nextleft=left->next;
        Node* nextright=right->next;

        left->next=right;
        right->next=nextleft;
        tail=right;
        left=nextleft;
        right=nextright;
     }
     if(right!=NULL){
        tail->next=right;
     }

     return head;
}

int main(){
    List ll;
    ll.push_front(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    printList(ll.head);
    // ll.head=mergesort(ll.head);//returns new head
    ll.head=ZigZag(ll.head);
    printList(ll.head);

    return 0;
}
// 1->2->3->4->5->NULL
// 1->5->2->4->3->NULL
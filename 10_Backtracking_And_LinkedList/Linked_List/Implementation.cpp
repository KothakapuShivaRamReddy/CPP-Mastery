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
      ~Node(){
        // cout<<"~Node"<<data<<endl;
        if(next!=NULL){
            delete next;
            // cout<<"~node"<<data<<endl;
            next=NULL;
        }
      }

};

class List{
    Node* head;
    Node* tail;

    public:
       List(){
         head=NULL;
         tail=NULL; 
       }
       ~List(){
        //  cout<<"~List"<<endl;
         if(head!=NULL){
            delete head;
            head=NULL;
         }
         
       }

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
        }
        void printList(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }

        void insert(int val,int pos){
            Node* newNode=new Node(val);
            Node* temp=head;
            for(int i=0;i<pos-1;i++){
                if(temp==NULL){
                    cout<<"THe position is INVALID"<<endl;
                }
                temp=temp->next;

            }

            newNode->next=temp->next;
            temp->next=newNode;

        }
        void pop_front(){
            if(head==NULL){
                cout<<"Empty linked list\n";
            }
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }

        // void pop_back(){
        //     if(head==NULL){
        //          cout<<"Empty linked list\n";
        //     }
        //     Node* temp=head;
        //     Node* prev=NULL;
        //     if(head->next==NULL){
        //         delete head;
        //         head=NULL;
        //         tail=NULL;
        //         return;

        //     }
           
        //     while(temp->next!=NULL){
        //             prev=temp;
        //             temp=temp->next;

        //     }
        //     prev->next=NULL;
        //     delete temp;
        //     tail=prev;
        
        // }
        void pop_back(){

              if(head->next==NULL){
                delete head;
                head=NULL;
                tail=NULL;
                return;
              }
              Node* temp = head;
              
              while(temp->next->next != NULL) {
                     temp = temp->next;
               }
            temp->next = NULL; //temp = tail's prev
            delete tail;
            tail = temp;}

        int searchItr(int key){
            Node*temp=head;
            int idx=0;
            while(temp!=NULL){
                if(temp->data==key){
                    return idx;
                }
                temp=temp->next;
                idx++;
            }
            return -1;
        }

        int helper(Node* h,int key){
            if(h==NULL){
                return -1;
            }
            if(h->data==key){
                return 0;
            }
            int idx=helper(h->next,key);
            if(idx==-1){
                return -1;
            }
            return idx+1;
        }
        int searchRec(int key){
               return helper(head,key);  
        }

        void reverse(){
           Node* curr=head;
           Node* prev=NULL;
           tail=head;//initially make tail as head
           while(curr!=NULL){
              Node* next=curr->next;
              curr->next=prev;
              prev=curr;
              curr=next;
           }
           head=prev;
        }
        int getSize(){
            Node* temp=head;
            int sz=0;
            while(temp!=NULL){
                temp=temp->next;
                sz++;

            }
            return sz;

        }
        void removeNth(int n){
            int size=getSize();
            Node* prev=head;
            for(int i=1;i<(size-n);i++){
                prev=prev->next;
            }
            // Node* toDel=prev->next;
            // cout<<"going to delete:"<<toDel->data<<endl;
            prev->next=prev->next->next;
        }

};

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1 );
    // ll.push_back(5);
    // ll.insert(4,3);
    // ll.pop_front();
    // ll.pop_back();
//    cout<<ll.searchRec(3)<<endl;
    ll.printList();
    // ll.reverse();
    ll.removeNth(2);
    ll.printList();
    return 0;
}
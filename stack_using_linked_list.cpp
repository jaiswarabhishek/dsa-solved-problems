#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

// same as insertAtTail
void push(node* &head,int val){


     node* n = new node(val);
     node* temp = head;
      
      if(head==NULL){
        head=n;
        return;
      }
    
     while(temp->next!=NULL){
        temp= temp->next;
     }
     temp->next=n;
     
}

//same as deleteFromEnd

void pop(node* &head){
    if(head==NULL){
        cout<<"Deletion not possible..."<<endl;
        return;
    }

    node* temp = head;
    
    
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
 node* nodeDelete = temp->next->next;
    temp->next=NULL;

    delete nodeDelete;

}

void display(node* head){
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main(){
  node* head=NULL;
  push(head,1);
  push(head,2);
  push(head,3);
  push(head,4);
  pop(head);
  pop(head);
  
  display(head);
    return 0;
}

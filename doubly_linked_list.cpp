#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){

   node* n = new node(val);

   n->next=head;

   if(head!=NULL)
   head->prev=n;

   head=n;
}

void insertAtTail(node* &head,int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }


    node* n = new node(val);

    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
     
    temp->next=n;
    n->prev = temp;

}


void insertAtPos(node* &head,int val,int pos){

   if(pos==1)
   {
  insertAtHead(head,val);
  return;
   }

   node* n = new node(val);

   node* temp = head;
  int count=1;

   while(temp!=NULL&&count!=pos-1){
    temp=temp->next;
    count++;
   }

   n->next=temp->next;
   temp->next->prev=n;
   temp->next=n;
   n->prev=temp;
 
}

void deleteAtHead(node* &head){
  
  node* temp=head;

  head=temp->next;
  temp->next->prev=NULL;
  
  delete temp;

}


void atDelete(node* &head,int pos){

  if(head==NULL)
  {
    cout<<"Deletion not possible..."<<endl;
    return;
  }

  if(pos==1){
    deleteAtHead(head);
    return;
  }

  node* temp = head;
 
  int count=1;
  while(temp!=NULL && count!=pos ){
    temp=temp->next;

    count++;
  }

  temp->prev->next=temp->next;

  if(temp->next!=NULL)
  temp->next->prev=temp->prev;
  
  delete temp;
}


void display(node* head){

node* temp = head;

  if(head==NULL)
  {
    cout<<"Empty list...."<<endl;
   
  }

  else{
      while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
      }
  }

}


int main(){
   node* head =NULL;
  insertAtHead(head,1);
  insertAtHead(head,2);
  insertAtHead(head,3);
  insertAtHead(head,5);
  insertAtTail(head,7);
  insertAtTail(head,4);
   
  display(head);
    return 0;
}





















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

void insertAtHead(node* &head,int val){
node* n = new node(val);
   n->next=head;
   head=n;
}


void insertAtPos(node* &head,int val,int pos){
  
 if(pos==1){
 insertAtHead(head,val);
 return;
 }

  int count=0;
  node* n = new node(val);
  node* temp=head;

  while(temp!=NULL){
  count++;
  if(count==pos-1)
  break;
  temp=temp->next;
  }

  n->next=temp->next;
  temp->next=n;

}

void insertAtTail(node* &head,int val){

    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp = head;  // it just like iterator

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;

}

int length(node* head){
    node* temp=head;
    int len=0;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}

node* appendKnodes(node* &head,int k){
  
 node* newHead;
 node* newTail;
 node* temp=head;

 int count=1;
 int len=length(head);

 k=k%len;

 while(temp->next!=NULL){

    if(count==len-k)
    newTail=temp;

    if(count==len-k+1)
    newHead=temp;

    temp=temp->next;
    count++;
 }

 newTail->next=NULL;
 temp->next=head;

 return newHead;

}


void display(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main(){

    node* head=NULL;

    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,9);
    insertAtHead(head,1);
    insertAtHead(head,0);

    node* newHead = appendKnodes(head,4);
   
    display(newHead);
   


    return 0;
}
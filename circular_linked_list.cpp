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
    node* temp=head;

    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }

    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void deleteFromStart(node* &head){
    node* nodeDelete = head;
    node* temp=head;


    if(head==NULL){
        cout<<"Deletion not possible..."<<endl;
        return;
    }
    if(head->next==head){
      head=NULL;
      delete temp;
      return;
    }

    while(temp->next!=head){
        temp=temp->next;
    }

     temp->next=temp->next->next;
     head = nodeDelete->next;

     delete nodeDelete;
}


void deleteAtPos(node* &head,int pos){
     
     node* temp = head;
    int count=1;

     if(head==NULL){
    cout<<"List is empty...."<<endl;
     return;
     }
     
     if(pos==1){
     deleteFromStart(head);
     return;
     }
         
         while(temp!=NULL&&count!=pos-1)
         {
            temp=temp->next;
            count++;
         }
         node* nodeDelete=temp->next;
         temp->next=temp->next->next;
        
        delete nodeDelete;

}

void deleteFromEnd(node* &head){

    node* temp =head;

     if(head==NULL){
        cout<<"Deletion not possible..."<<endl;
        return;
    }

    if(head->next==head){
      head=NULL;
      delete temp;
      return;
    }

    while(temp->next->next!=head)
    {
    temp=temp->next;
    }

    node* nodeDelete = temp->next;
    temp->next=head;


 delete nodeDelete;
}

void display(node* head){
    node* temp = head;
        
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}

int main(){

    node* head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    deleteAtPos(head,2);
    
   
    display(head);
    return 0;
}
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

// enqueue is same as insertAtTail
void enqueue(node* &head,int val){
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

// Dequeue is same as deleteFrom start

void dequeue(node* &head){
if(head==NULL)
    {
        cout<<"List is empty..."<<endl;
        return;
    }
    node* temp = head;


   head=temp->next;

   delete temp; 
}

void display(node* head){
node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

bool search(node* head,int key){

    node* temp =head;
    while(temp!=NULL){
        if(key==temp->data)
        return true;

        temp=temp->next;
    }
    return false;
}

int main(){

node* head=NULL;

enqueue(head,1);
enqueue(head,2);
enqueue(head,3);
dequeue(head);
dequeue(head);
display(head);

    return 0;
}
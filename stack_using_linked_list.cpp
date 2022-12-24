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

// same as insertAtBegin
void push(node* &head,int val){


    node* n = new node(val);
   n->next=head;
   head=n;
     
}

//same as deleteFromStart

void pop(node* &head){
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
  pop(head);
  
  display(head);
    return 0;
}

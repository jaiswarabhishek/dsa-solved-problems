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

void deleteFromHead(node* &head){

    if(head==NULL)
    {
        cout<<"List is empty..."<<endl;
        return;
    }
    node* temp = head;


   head=temp->next;

   delete temp;  
}

void atDelete(node* &head,int val){
     
     node* temp = head;

     if(head==NULL){
    cout<<"List is empty...."<<endl;
     return;
     }
     
     if(head->next==NULL){
    deleteFromHead(head);
    return;
     }

     while(temp->next->data!=val){
        temp=temp->next;
     }

     node* nodeDelete = temp->next;
     temp->next=temp->next->next;

     delete nodeDelete;

}

node* reverse(node* &head){

    node* prevPtr = NULL;
    node* currPtr=head;
    node* nextPtr;

    while(currPtr!=NULL){
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
         
         prevPtr=currPtr;
         currPtr=nextPtr;
    }
    return prevPtr;
}

void sort(node* &head){
    node* i;
    node* j;
    int temp;

    for(i=head;i->next!=NULL;i=i->next){
        for(j=head;j->next!=NULL;j=j->next){
            if(j->data > j->next->data){
                temp=j->data;
                j->data=j->next->data;
                j->next->data=temp;
            }
        }
    }
}

node* reverseknodes(node* &head,int k){
    node* prevPtr=NULL;
    node* currPtr=head;
    node* nextPtr;
    int count=0;

    while(currPtr!=NULL && count<k){
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;
       count++;
    }

     if(nextPtr!=NULL){
    head->next=reverseknodes(nextPtr,k);
     }
 
   return prevPtr;
}

void makeCycle(node* &head,int pos){

int count = 1;
node* temp=head;
node* startNode;

while(temp->next!=NULL){

    if(count==pos){
        startNode=temp;
    }
    temp=temp->next;
    count++;
}

temp->next=startNode;

}

bool detectCycle(node* head){
        node* slow=head;
        node* fast=head;

        while(fast!=NULL && fast->next!=NULL){
             slow=slow->next;
             fast=fast->next->next;

             if(slow==fast){
               return true; 
             }

        }

        return false;

}

void removeCycle(node* &head){

    node* slow=head;
    node* fast=head;

    do{
     slow=slow->next;
     fast=fast->next->next;
    }while(slow!=fast);

fast=head;

    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
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

    node* head =NULL;
   
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    // display(reverse(head));
    // display(reverseknodes(head,2));

    display(head);

    
    return 0;
}
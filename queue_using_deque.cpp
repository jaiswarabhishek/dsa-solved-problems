#include<iostream>
using namespace std;
#define size 10

class deque{
    int* arr;
    int front;
    int rear;
 
 public:
    deque(){
   arr = new int [size];
   front=size/2;
   rear=size/2;
    }

//    rightInsert similar to push operation

void enqueue(int val){
    if(rear==size+1)
    cout<<"Insertion not possible..."<<endl;

    else{
        arr[rear]=val;
        rear++;
    }

}

// DeleteFromLeft similar to pop

void dequeue(){
    if(front==rear)
    cout<<"Deletion not possible"<<endl;

    else{
        front++;
    }
}


  void display(){
        if(front==rear)
        cout<<"Queue is empty..."<<endl;

        else{
            for(int i=front;i<rear;i++)
            cout<<arr[i]<<endl;
        }
    }

};

int main(){
    
    deque dq;
    dq.enqueue(1);
    dq.enqueue(2);
    dq.enqueue(3);
    dq.dequeue();
    dq.display();
 
    return 0;

}
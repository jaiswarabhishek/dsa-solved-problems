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

//    leftInsert similar to push operation

void push(int val){
    if(front==-1)
    cout<<"Insertion not possible..."<<endl;

    else{
        arr[front]=val;
        front--;
    }

}

// DeleteFromLeft similar to pop

void pop(){
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
            for(int i=front+1;i<=rear;i++)
            cout<<arr[i]<<endl;
        }
    }

};

int main(){
    
    deque dq;
    dq.push(1);
    dq.push(2);
    dq.push(3);
    dq.pop();
    dq.pop();
    dq.display();
 
    return 0;

}
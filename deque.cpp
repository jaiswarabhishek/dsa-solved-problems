#include<iostream>
using namespace std;
#define size 10

class deque{
    int* arr;
    int front;
    int rear;
   public:
    deque(){
        arr = new int[size];
        front=size/2;
        rear=size/2;
    }

    void leftInsert(int x){
        if(front==-1)
        cout<<"Queue Overflow..."<<endl;

        else{
            arr[front]=x;
            front--;
        }
    }

    void rightInsert(int x){
        if(rear==size-1)
        cout<<"Queue Overflow..."<<endl;
        else{
            rear++;
            arr[rear]=x;
        }
    }

    int deleteFromLeft(){
        int x;
        if(front==rear)
        return -1;
        
        else{
            front++;
            x=arr[front];
            return x;
        }
    }

    int deleteFromRight(){
        int x;
        if(front==rear)
        return -1;

        else{
            x=arr[rear];
            rear--;
            return x;
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

    bool isEmpty(){
        return front==rear;
    }




};

int main(){
   deque dq;
   dq.leftInsert(10);
   dq.leftInsert(11);
   dq.leftInsert(12);
   dq.rightInsert(14);
   dq.rightInsert(15);
   dq.rightInsert(17);
   cout<<dq.deleteFromLeft()<<endl;
   cout<<dq.deleteFromRight()<<endl;
   dq.display();

    return 0;
}
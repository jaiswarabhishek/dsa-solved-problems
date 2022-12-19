#include<iostream>
using namespace std;
#define size 100

class queue {
    int* arr;
    int front;
    int rear;

    public:
    queue(){
        arr = new int[size];
        front=-1;
        rear=-1;
    }

    void enqueue(int x){
        if(rear==size-1)
        cout<<"Queue overflow..."<<endl;
        else{
            rear++;
            arr[rear]=x;

            if(front==-1)
            front++;   
        }
    }

    void dequeue(){
        if(front==-1||front>rear){
            cout<<"Queue Underflow..."<<endl;
        }

        else{
        front++;
        }
    }

  
  int peek(){
    if(front==-1||front>rear){
            return -1;
        }

        else{
            return arr[front];
        }
  }

  bool isEmpty(){
     if(front==-1||front>rear){
            return true;
        }
        else{
            return false;
        }
  }

};

int main(){

    queue q;

    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;

     q.dequeue();
     q.dequeue();
     cout<<q.isEmpty()<<endl;
    return 0;
}
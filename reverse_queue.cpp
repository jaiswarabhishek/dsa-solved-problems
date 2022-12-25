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

  void reverse(){
     
     int x = peek();
     dequeue();

     if(!isEmpty())
     reverse();

     enqueue(x);
  }

  void display(){

    for(int i=front;i<=rear;i++){
        cout<<arr[i]<<" ";
    }
  }

};

int main(){
// 4 3 1 10 2 6
// 6 2 10 1 3 4
    queue q;
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(10);
    q.enqueue(2);
    q.enqueue(6);
 
    q.display();
    q.reverse();
    cout<<endl;
    q.display();

    return 0;
}
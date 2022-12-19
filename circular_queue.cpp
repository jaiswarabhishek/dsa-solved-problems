#include<iostream>
using namespace std;
#define size 5

class circularQueue{
    int* arr;
    int front,rear,count;
 
   public:
    circularQueue(){
        arr = new int[size];
        front=-1;
        rear=-1;
        count=0;
    }

    void enqueue(int x){
        if(count==size)
        cout<<"Queue Overflow..."<<endl;
        else
        {
            count++;
            rear=(rear + 1)%size;
            arr[rear]=x;

            if(front==-1)
            front=0;
        }
    }


    void dequeue(){
        if(count==0)
        cout<<"Queue underflow..."<<endl;

        else{
            count--;
            front=(front + 1)%size;
        }
    }

    bool isFull(){

        return count==size;

    }


    void display(){
        int i;
        for(i=front;i!=rear;i=(i+1)%size)
        cout<<arr[i]<<endl;

        cout<<arr[i]<<endl;
    }


};

int main(){

 circularQueue cq;
 cq.enqueue(10);
 cq.enqueue(11);
 cq.enqueue(12);
 cq.enqueue(13);
 cq.enqueue(14);
 cq.dequeue();
 cq.dequeue();
 cq.enqueue(10);
 cq.enqueue(11);
 cq.display();

 cout<<cq.isFull()<<endl;

 



    return 0;
}
#include<iostream>
using namespace std;
#define size 10

class priorityQueue{
    int* arr;
    int front;
    int rear;

    public:
    priorityQueue(){
        arr = new int[size];
        rear=-1;
        front=-1;
    }

    void enqueue(int x){

        if(rear==size-1)
        cout<<"Queue Overflow..."<<endl;

        else{
            rear++;
            arr[rear]=x;

            if(front==-1)
            front=0;
        }

    }

    int dqueue(){
             
        int max,pos;
        if(front==rear+1)
        return -1;

        else{
            max=arr[front];
            pos=front;
            for(int i = front+1;i<=rear;i++)
            {
                if(max<arr[i])
                {
                    max=arr[i];
                    pos=i;
                }
            } 
           
           for(int i=pos;i<rear;i++){
            arr[i]=arr[i+1];
           }
        }

        return max;

    }
    
    void display(){
        if(front==rear+1)
        cout<<"Empty"<<endl;
        else{
            for(int i=front;i<rear;i++)
            cout<<arr[i]<<endl;
        }
    }

};

int main(){

  priorityQueue pq;

  pq.enqueue(10);
  pq.enqueue(11);
  pq.enqueue(12);
  pq.enqueue(43);
  pq.enqueue(43);
  pq.enqueue(23);
 cout<<pq.dqueue()<<endl;
  pq.display();

    return 0;
}
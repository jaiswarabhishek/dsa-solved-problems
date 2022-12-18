#include<iostream>
using namespace std;
#define size 100

class stack {

    int* arr;   // created dynamic array
    int top;

    public:

    stack(){
        arr = new int [size];
        top=-1;
    }

    void push(int num){

        if(top==size-1)
        cout<<"Stack Overflow...."<<endl;

        else
        {
          top++;
          arr[top]=num;
        }
        
    }

    void pop(){
        if(top==-1){
        cout<<"Stack Underflow..."<<endl;
        return;
        }

        else{
            top--;
        }
    }

    int peek(){

        if(top==-1)
        {
      cout<<"Stack is empty..."<<endl;
        return -1;
        }

        else
        return arr[top];
    }

    bool empty(){
        return top==-1;
    }

};

int main(){

    stack st;   // stack object created
    
    st.push(10);    // invoking push function using stack obj.
    st.push(20);
    st.push(30);
    st.push(30);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;

    return 0;
}
















#include<iostream>
using namespace std;
#define size 10

class twoStack{
    int* arr;
    int top1;
    int top2;
    
    public:
    twoStack(){
        arr = new int[size];
        top1=-1;
        top2=-1;
    }

    void push1(int val){
        if(top1==size-1)
        cout<<"Stack overflow..."<<endl;

        else{
            top1++;
            arr[top1]=val;
        }
    }

    void pop1(){
        if(top1==-1)
        cout<<"Stack Underflow..."<<endl;

        else{
            top1--;
        }
    }

    int peek1(){
        if(top1==-1)
        return -1;
        else
        return arr[top1];
    } 
    
    
     void push2(int val){
        if(top2==size-1)
        cout<<"Stack overflow..."<<endl;

        else{
            top2++;
            arr[top2]=val;
        }
    }

    void pop2(){
        if(top2==-1)
        cout<<"Stack Underflow..."<<endl;

        else{
            top2--;
        }
    }

    int peek2(){
        if(top2==-1)
        return -1;
        else
        return arr[top2];
    }


};



int main(){

    twoStack st;
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push1(4);
    st.push2(5);
    st.push2(6);
    st.pop1();
    st.pop2();

    cout<<st.peek1()<<endl;
    cout<<st.peek2()<<endl;
    
    return 0;
}
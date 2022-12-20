#include<bits/stdc++.h>
using namespace std;

class Stack{

    queue<int>q1;
    queue<int>q2;
 
  public:
    void push(int x){
        q1.push(x);
    }

    void pop(){
        if(q1.empty())
        cout<<"Queue underflow..."<<endl;

        else{

           while(q1.size()!=1)
           {
            q2.push(q1.front());
            q1.pop();
           }

        q1.pop();

           queue<int>temp = q1;
           q1 = q2;
           q2=temp; 
            
        }

    }

    int top(){
       if(q1.empty())
       return -1;

       while(q1.size()!=1){
        q2.push(q1.front());
        q1.pop();
       }

       int ans = q1.front();
       q2.push(ans);

 queue<int>temp = q1;
           q1 = q2;
           q2=temp; 

           return ans;



    }


};

int main(){
Stack st;
st.push(10);
st.push(11);
st.push(12);
st.pop();
st.pop();
st.pop();
cout<<st.top()<<endl;
    return 0;
}
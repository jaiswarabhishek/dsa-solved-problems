//Here we using callStack recurive method


#include<bits/stdc++.h>
using namespace std;

class que {
    stack<int>s1;
    

    public:

    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty() )
        return -1;

        int x = s1.top();
       
        s1.pop();

        if(s1.empty())
        return x;

        int item = pop();
       
     
        s1.push(x);

        return item;

        
    }

    bool isEmpty(){
        return s1.empty();
    }


};


int main(){
 que q;
 q.push(1);
 q.push(2);
 q.push(3);
 q.push(4);

 q.pop();
 q.pop();



    return 0;
}
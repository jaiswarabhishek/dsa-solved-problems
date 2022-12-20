//implementing queue using stack
// here we are using two stack
//Time Complexity for push operation is O(1) and for pop is O(n)

#include<bits/stdc++.h>
using namespace std;

class que {
    stack<int>s1;
    stack<int>s2;

    public:

    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty() && s2.empty())
        return -1;

        if(s2.empty())
        {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            
        }
        int topval = s2.top();
            s2.pop();
            return topval;
    }

    bool isEmpty(){
        return s1.empty()&&s2.empty();
    }


};


int main(){
 que q;
 q.push(10);
 q.push(11);
 q.push(12);

 cout<<q.pop()<<endl;
 cout<<q.pop()<<endl;
 cout<<q.pop()<<endl;
 cout<<q.pop()<<endl;


    return 0;
}

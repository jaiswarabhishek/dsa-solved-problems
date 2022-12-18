#include<bits/stdc++.h>
using namespace std;

int postfixEvaluation(string str){
    stack<int>st;
    int op1;
    int op2;

    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9')
        st.push(str[i]-'0');

        else if(str[i]=='+'){
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            st.push(op1 + op2);
        }
        else if(str[i]=='-'){
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            st.push(op1 - op2);
        }
        else if(str[i]=='*'){
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            st.push(op1 * op2);
        }
        
        else if(str[i]=='/'){
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            st.push(op1 / op2);
        }
    }

    return st.top();

}


int main(){

string str="46+2/5*7+";

  cout<<"The evaluation of given postfix notation is "<<postfixEvaluation(str)<<endl;

    return 0;
}
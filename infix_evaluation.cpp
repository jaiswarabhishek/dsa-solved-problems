#include<bits/stdc++.h>
using namespace std;

int prefixEvaluation(string str){

    stack<int>st;
    int op1,op2;

    for(int i=str.length()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9')
        st.push(int(str[i])-48);

        else if(str[i]=='+')
        {
            op1=st.top();
            st.pop();
            op2=st.top();
            st.pop();

            st.push(op1+op2);

        }

        else if(str[i]=='-')
        {
            op1=st.top();
            st.pop();
            op2=st.top();
            st.pop();

            st.push(op1-op2);
        }
        
        else if(str[i]=='*')
        {
            op1=st.top();
            st.pop();
            op2=st.top();
            st.pop();

            st.push(op1*op2);
        } 
        
        else if(str[i]=='/')
        {
            op1=st.top();
            st.pop();
            op2=st.top();
            st.pop();

            st.push(op1/op2);
        }
    }

    
    return st.top();


}

int main(){

    string str="*+69-31";

    cout<<"The Evaluation of given prefix notation is "<<prefixEvaluation(str)<<endl;


return 0;
}
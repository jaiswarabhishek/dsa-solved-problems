#include<bits/stdc++.h>

using namespace std;

bool isValid(string str){
    stack<char> st;

    for(int i=0;i<str.size();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        st.push(str[i]);

        else if (str[i]==')'){
            if(!st.empty() && st.top()=='(')
            st.pop();
            else
            return false;
        }

        else if(str[i]=='}'){
            if(!st.empty() && st.top()=='{')
            st.pop();
            else
            return false;
        }

        else if(str[i]==']'){
            if(!st.empty() && st.top()=='[')
            st.pop();

            else
            return false;
        }
    }

    if(st.empty())
    return true;
    else
    return false;
    

}

int main(){

    string str = "{[((((())))]";

    if(isValid(str))
    cout<<"Balanced String..."<<endl;
    else
    cout<<"Unbalanced String..."<<endl;


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int prescendance(char x){
    if(x=='^')
    return 3;

    else if(x=='*' || x=='/')
    return 2;

    else if(x=='+' || x=='-')
    return 1;

    else 
    return -1;
}


string infixTopostfix(string str){

   stack<char> st;
   string postfix="";

   for(int i=0;i<str.length();i++){
   
   if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
    postfix+=str[i];

    else if(str[i]=='(')
    st.push(str[i]);

    else if(str[i]==')'){

        while(!st.empty() && st.top()!='(')
        {
            postfix+=st.top();
            st.pop();
        }
            
            if(!st.empty())
            st.pop();
    }

    else {

        while(!st.empty() && prescendance(st.top())>=prescendance(str[i])){
            postfix+=st.top();
            st.pop();
        }
        st.push(str[i]);

    }


   }

   while(!st.empty()){
    postfix+=st.top();
    st.pop();
  }

return postfix;


}

int main(){

    string str ="(a-b/c)*(a/k-l)";

    cout<<"Postfix expression for given Infix is "<<infixTopostfix(str)<<endl;

    return 0;
}
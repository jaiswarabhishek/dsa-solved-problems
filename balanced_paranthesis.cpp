#include<bits/stdc++.h>
using namespace std;

bool isValid(string str){

  stack<char> st;
  bool ans = true;

  for(int i=0;i<str.size();i++){
     
     if(str[i]=='(' or str[i]=='[' or str[i]=='{')
     st.push(str[i]);

      else if (str[i]==')'){
        if(!st.empty() and st.top()=='('){

            st.pop();
            
        }
        else{
            ans=false;
            break;
            
        }

      }

       else if (str[i]=='}'){
        if(!st.empty() and st.top()=='{'){
            
            st.pop();
            
        }
        else{
            ans=false;
            break;
        }

      }

       else if (str[i]==']'){
        if(!st.empty() and st.top()=='['){
            
            st.pop();
            
        }
        else{
            ans=false;
            break;
        }

      }
  }

if(!st.empty())
return false;
else
return ans;




}

int main(){

    string str="{[(()))]}";

    if(isValid(str)){
        cout<<"Balanced Paranthesis...."<<endl;
    }

    else
    cout<<"Not a balanced Paranthesis...."<<endl;


    return 0;
}
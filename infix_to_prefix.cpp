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


string infixToPrefix(string str){
    reverse(str.begin(),str.end());
   
    stack<char>st;
    string prefix="";

    for(int i=0;i<str.length();i++){
        if((str[i]>='a'&&str[i]<='z') ||(str[i]>='A'&&str[i]<='Z') )
        prefix+=str[i];

        else if(str[i]==')')
        st.push(str[i]);

        else if(str[i]=='('){
            while(!st.empty()&&st.top()!=')'){
                prefix+=st.top();
                st.pop();
            }
            
            if(!st.empty())
            st.pop();
        }

        else{
            while(!st.empty()&&prescendance(st.top())>=prescendance(str[i])){
                    prefix+=st.top();
                    st.pop();
            }
            st.push(str[i]);
        }


    }

 while(!st.empty()){
    prefix+=st.top();
    st.pop();
 }

 reverse(prefix.begin(),prefix.end());

 return prefix;


}


int main(){
  string str="a*(b+c+d)";

  cout<<"Prefix expression for given Infix is "<<infixToPrefix(str)<<endl;


    return 0;
}
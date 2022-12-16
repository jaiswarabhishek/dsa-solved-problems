#include<bits/stdc++.h>
using namespace std;

void reverseSent(string str){
    stack<string> s;

    for(int i=0;i<str.length();i++){
    string word="";
         
         while(str[i]!=' ' && i<str.length()){
            word+=str[i];
            i++;
         }
         s.push(word);
    }

    while(!s.empty()){
     cout<<s.top()<<" ";
     s.pop();
    }
    cout<<endl;

}

int main(){

    string sent = "Fun Fact, You are still alive!";

reverseSent(sent);


    return 0;
}
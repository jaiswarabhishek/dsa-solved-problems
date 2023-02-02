#include<bits/stdc++.h>
using namespace std;

int main(){
    // Multiple ways to declare a string

    // 1
    // string str;

    // 2
    // string str(5,'a');   // It will print 5 times character 'a'
   
     // 3
     string str = "Abhishek" ; // Directly assign the value to the string


// Multiple ways to input a string
 // 1
    // cin>>str;     // It will input string upto first space character

//2
// getline(cin,str);  // It will input whole string even space also

     
     // String Concatenation
    //  string s1= "Abhi";
    //  string s2 = "shek";
    //  s1.append(s2);    // It will append the string s2 into s1
    // s1 + s2  string concatenate

    
    //str.clear();  // It will delete the string

  
    // String Comparison

    //  s1.compare(s2)==0  // Equal string
    //  s1.compare(s2)>0  // s1 bigger
    //  s1.compare(s2)<0  // s2 bigger
     
    //  s1.empty() check string wether empty or not

    //   str.erase(index from where to delete , number of character want to  delete)
   //    str.erase(0,2);
   
// int idx = str.find("Abhi");   // find() function takes substring as input and return first matching char index

// str.insert(Startindex, character want to append)
// str.insert(0,"Hi ");

// str.size()   return number of char in the string


// string st = str.substr(startIndx,number of character)

// String to int
// string x = "100";
// cout<<stoi(x);

//int to String
// int x= 2;
// string st = to_string(x) + "Hello";
// cout<<st;

// sort(str.begin(),str.end());  // sort in ascending order lexicographically
cout<<str;
    return 0;
}

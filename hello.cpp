#include<bits/stdc++.h>

using namespace std;
// Time_complexity = O(n^2)
void bubble_sort(vector<int>&vec){
 
  for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec.size()-i-1;j++){
        if(vec[j]>vec[j+1]){
            int temp = vec[j+1];
            vec[j+1]=vec[j];
            vec[j]=temp;
        }
    }
  }

}

int main(){
    vector<int>vec={23,56,12,76,44,21,43,54};

    bubble_sort(vec);

    for(int i=0;i<vec.size();i++){
       cout<<vec[i]<<" ";
    }

    return 0;
}
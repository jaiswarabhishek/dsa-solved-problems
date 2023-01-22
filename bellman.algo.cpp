
#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(V x E)

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       
       
        vector<int>dis(V,1e8);
       
       
        dis[S]=0;
        
      
          for(int i=0;i<V-1;i++){
              for(auto it : edges){
                  if(dis[it[0]] + it[2] < dis[it[1]])
                  dis[it[1]]=dis[it[0]]+it[2];
              }
          }
          
         
              for(auto it : edges){
                  if(dis[it[0]] + it[2] < dis[it[1]])
                  return {-1};
              }
         
        
          return dis;
            
   
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

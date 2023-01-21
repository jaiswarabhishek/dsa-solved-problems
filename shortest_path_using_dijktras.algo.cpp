//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        vector<int>ans;
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dis(n+1);
        vector<int> parent(n+1);
        
        for(int i=1;i<=n;i++){
            dis[i]=1e9;
            parent[i]=i;
        }
        dis[1]=0;
        
        pq.push({0,1});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist  = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgWtg=it.second;
                int adjNode=it.first;
                
                if(edgWtg+dist<dis[adjNode])
                {
                    dis[adjNode]=edgWtg+dist;
                    pq.push({dis[adjNode],adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        
        while(parent[n]!=n){
            ans.push_back(n);
            n=parent[n];
        }
        if(ans.size()==0){
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
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

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
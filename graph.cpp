//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   private:
    void dfs(int node, vector<int>adj[],int visit[],vector<int>&dfsList ){
        visit[node]=1;
        dfsList.push_back(node);
        
        for(auto it : adj[node]){
            if(!visit[it]){
                dfs(it,adj,visit,dfsList);
            }
        }
    }

     bool detect(int src , int visit[] ,vector<int> adj[]){
        visit[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjnode : adj[node]){
                if(!visit[adjnode]){
                    visit[adjnode]=1;
                    q.push({adjnode,node});
                    
                }
                else if (parent!=adjnode)
                return true;
            }
        }
        
        return false;
        
    }


  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visit[V]={0};  //all the node assign to the zero
        
        visit[0]=1;
        queue<int> q;
        q.push(0);
        vector<int>bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
           
            for(auto it : adj[node]){
                if(!visit[it]){
                    visit[it]=1;
                    q.push(it);
                }
            }
           
        }
        return bfs;
        
    }

     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int visit[V] = {0};
        int start = 0;
        vector<int>dfsList;
        dfs(start,adj,visit,dfsList);
        return dfsList;
    }

     // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visit[V]={0};
        for(int i=0;i<V;i++){
            if(!visit[i])
        {
        if(detect(i,visit,adj))
        return true;
        }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
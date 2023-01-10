
#include <bits/stdc++.h>
using namespace std;

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

     bool detectUsingBFS(int src , int visit[] ,vector<int> adj[]){
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

    bool detectUsingDFS(int node , int parent ,int visit[],vector<int> adj[] ){
        visit[node]=1;

        for(auto it : adj[node]){
            if(!visit[it]){
                if(detectUsingDFS(it,node,visit,adj))  // This line recursively return true
                return true;
            }
            else if (parent!=it)
            return true;
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

     // Function to detect cycle in an undirected graph using BFS method.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visit[V]={0};
        for(int i=0;i<V;i++){
            if(!visit[i])
        {
        if(detectUsingBFS(i,visit,adj))  //For Multiple Component Graph
        return true;
        }
        }
        return false;
    }
     
    // Function To detect cycle in an undirected graph using DFS method
    bool isCycleDFS(int V , vector<int>adj[]){
        int visit[V]={0};  

        detectUsingDFS(0,-1,adj,visit);  //For Single Component Graph

    }


};


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

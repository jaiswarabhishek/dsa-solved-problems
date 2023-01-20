#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);  //1-based indexing
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }

//Path Compression finding parent for given node
    int findPar(int node){
        if(node==parent[node])
        return node;

        return parent[node]=findPar(parent[node]);
    }

// UnionByRank connecting the two nodes
    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u==ulp_v)
        return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }

};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
   {
       //          {wt,     {u,v}}
       vector<pair<int,pair<int,int>>> edges;  
       
       //Time Complexity O(V+E)
       for(int i=0;i<V;i++){
         for(auto it : adj[i]){
             int u = it[0];
             int wt = it[1];
             edges.push_back({wt,{i,u}});
         }   
       }
       
       //Time Complexity O(NlogN)
       sort(edges.begin(),edges.end());
       int mst=0;
       DisjointSet ds(V);
       
       //TimeComplexity O(E*4*alpha*2)
       for(auto it : edges){
           
           int wgt = it.first;
           int u = it.second.first;
           int v=it.second.second;
           if(ds.findPar(u)!=ds.findPar(v))
           {
               mst+=wgt;
               ds.unionByRank(u,v);
           }
       }
       return mst;
       
       
       
   }
};




int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}



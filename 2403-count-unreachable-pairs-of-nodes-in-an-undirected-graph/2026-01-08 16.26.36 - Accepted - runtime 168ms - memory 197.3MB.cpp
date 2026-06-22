class Solution {
public:
    int dfs(int node,vector<vector<int>>&adj,vector<bool> &vis){
        int sum =0;
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                vis[neigh]=true;
                sum+=dfs(neigh,adj,vis);
            }
        }
        return sum +1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int> >adj(n);
        vector<bool> vis(n,false);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long pairs=0,remaining=n;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                int size= dfs(i,adj,vis);
                remaining-=size;
                pairs += 1LL * size* remaining;
               
            }
        }
      
        
        return pairs;
    }
};
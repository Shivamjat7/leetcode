class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<bool>&vis){
        vis[node]=true;
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<int> adj[n];
        vector<bool>vis(n,false);
        for(auto edge:connections){
            int u =edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components =0;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                components++;
            }
        }
        return components-1;
        

    }
};
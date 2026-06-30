class Solution {
public:
    vector<int>disc,low;
    int timer=0;
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis,vector<vector<int>>&bridges){
        vis[node]=1;
        disc[node]=low[node]=timer;
        timer++;
        for(int neigh:adj[node]){
            if(neigh==parent)continue;
            if(!vis[neigh]){
                
                dfs(neigh,node,adj,vis,bridges);
                low[node]=min(low[node],low[neigh]);
                if(disc[node]<low[neigh]){
                    bridges.push_back({node,neigh});
                }
            }else{
                low[node]=min(low[node],disc[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        disc.assign(n,0);
        low.assign(n,0);
        for(auto &e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        vector<vector<int>>bridges;
        dfs(0,-1,adj,vis,bridges);
        return bridges;
    }
};
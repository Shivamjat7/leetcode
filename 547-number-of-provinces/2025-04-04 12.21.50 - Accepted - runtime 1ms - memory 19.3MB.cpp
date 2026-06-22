class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        if(adj.empty()) return 0;
        vector<bool> visited(adj.size(),false);
        int cnt=0;

        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                cnt++;
                visited[i]=true;
                dfs(adj,visited,i);
            }
        }
        return cnt;
    }
    void dfs(vector<vector<int>> &adj,vector<bool> & visited,int v){
        for(int u =0;u<adj[v].size();u++){
            if( adj[v][u]==1 && !visited[u]){
                visited[u]=true;
                dfs(adj,visited,u);
            }
        }
    }
};
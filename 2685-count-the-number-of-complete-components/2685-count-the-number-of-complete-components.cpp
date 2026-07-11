class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n,false);
        queue<int>q;
        int ans =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                int e=0;
                int v=0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    e+=adj[node].size();
                    v++;
                    for(int neigh:adj[node]){
                        if(!vis[neigh]){
                            vis[neigh]=true;
                            q.push(neigh);
                        }
                    }
                }
                if(e==((v-1)*v)|| (e==0 && v==1))ans++;
            }
        }
        return ans;
    }
};
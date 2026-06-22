class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(auto path:paths){
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }
        vector<int> ans (n,0);
        for(int i =1;i<=n;i++){
            if(ans[i-1])continue;
            vector<bool>color(5,false);
            for(int neigh:adj[i]){
                color[ans[neigh-1]]=true;
            }
            for(int j=1;j<5;j++){
                if(!color[j]){
                    ans[i-1]=j;
                    break;
                }
            }
        }
        return ans;

        
    }
};
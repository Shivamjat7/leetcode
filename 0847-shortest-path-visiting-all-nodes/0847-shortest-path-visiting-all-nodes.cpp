class Solution {
public:

    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int ,int>>q;
        int n =graph.size();
        for(int i=0;i<n;i++) q.push({i,1<<i});
        vector<vector<bool>> vis(n, vector<bool>(1<<n, false));
        int dst=0;
        while(!q.empty()){
            int level =q.size();
            while(level--){
            auto [node,mask ]=q.front();
            q.pop();
            if(mask==((1<<n)-1))return dst;
            
            for(int next:graph[node]){
                if(!vis[next][mask|1<<next]){
            vis[next][mask|1<<next]=true;
                    
                q.push({next,mask|1<<next});}
            }}
            dst++;
        }
        return dst;
    }
};
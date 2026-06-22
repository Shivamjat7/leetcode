class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
       vector<vector<pair<int,int>>> adj(n) ;
       for(auto &e:edges){
            int u =e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
       }
       vector<int>dist(n,1e9);
       dist[0]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,0});
       while(!pq.empty()){
        auto[dst ,node]=pq.top();
        pq.pop();
        if(dst>dist[node])continue;
        for(auto [v,w]:adj[node]){
            if( dst+w<dist[v]){
                dist[v]=dst+w;
                pq.push({dist[v],v});
            }
        }
       }
       return dist[n-1]==1e9?-1:dist[n-1];
    }
};
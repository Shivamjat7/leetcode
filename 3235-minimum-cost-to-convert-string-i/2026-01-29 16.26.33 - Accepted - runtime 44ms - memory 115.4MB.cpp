class Solution {
public:
    vector<long long> minCost(int src,vector<vector<pair<int,int>>>&adj){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<long long>dist(27,1e9);
        dist[src]=0;
        pq.push({0,src});
    while(!pq.empty()){
        auto[d,node]=pq.top();
        pq.pop();
        if(d>dist[node])continue;
        for(auto [v,w]:adj[node]){
            if(d+w<dist[v]){
                dist[v]=d+w;
                pq.push({d+w,v});
            }
        }
    }
     return dist;

    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>>adj(27);
        for(int i =0;i<original.size();i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<long long >>dist(27,vector<long long>(27,1e9));
        for(int i=0;i<27;i++){
            dist[i]=minCost(i,adj);
        }
        long long sum =0;
        for(int i=0;i<source.size();i++){
            int src =source[i]-'a';
            int dst = target[i]-'a';
            if(dist[src][dst]==1e9)return -1;
            else sum +=dist[src][dst];
        }
      return sum ;
    }
};
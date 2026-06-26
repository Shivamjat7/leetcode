class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        for(auto &edge:relations){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int>indegree(n+1,0);
        for(int i=1;i<=n;i++){
            for(int node:adj[i]){
                indegree[node]++;
            }
        }
        vector<int>prefixTime(n+1,0);
        priority_queue<pair<int,int>>pq;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                prefixTime[i]=time[i-1];
                pq.push({time[i-1],i});
            }
        }
        int mxTime =0;
        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();
            if(t<prefixTime[node])continue;
            mxTime = max(t,mxTime);
            for(int neigh:adj[node]){
                if(t+time[neigh-1]>prefixTime[neigh]){
                    prefixTime[neigh]=t+time[neigh-1];
                    pq.push({prefixTime[neigh],neigh});
                }
            }
        }
        return mxTime;
        
    }
};
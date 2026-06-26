class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1,0);
        for(auto &edge:relations){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
      
        vector<int>dp(n+1,0);
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                dp[i]=time[i-1];
                q.push(i);
            }
        }
        int ans =0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans = max(dp[node],ans);
            for(int neigh:adj[node]){
               indegree[neigh]--;
            dp[neigh]=max(dp[neigh],dp[node]+time[neigh-1]);
               if(indegree[neigh]==0){
                q.push(neigh);
               }
               
            }
        }
        return ans;
        
    }
};
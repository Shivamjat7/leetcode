class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto & edge:prerequisites){
            int u = edge[0];
            int v= edge[1];
            adj[v].push_back(u);
        }
        vector<int> indegree (V,0);
        for(int i =0;i<V;i++){
            for(int j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i =0;i<V;i++){
            if(!indegree[i]) q.push(i);
        }
        int cnt =0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;
            for(int neighbour:adj[node]){
                indegree[neighbour]--;
                if(!indegree[neighbour])q.push(neighbour);
            }
        }
        return cnt==V;
    }
};
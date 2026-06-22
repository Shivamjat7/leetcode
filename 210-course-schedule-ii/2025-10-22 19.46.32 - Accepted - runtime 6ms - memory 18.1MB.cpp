class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
vector<vector<int>> adj(V);
for (auto &edge : prerequisites) {
    int u = edge[1];  // from
    int v = edge[0];  // to
    adj[u].push_back(v);
}

       if ((int)adj.size() < V) adj.resize(V); 
        vector<int> indegree(V,0);
        for(int i =0;i<V;i++){
            for(int neighbour:adj[i]) indegree[neighbour]++;
        }
        queue <int> q;
    for(int i =0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto neighbour:adj[node]){
                indegree[neighbour]--;
                if(!indegree[neighbour])q.push(neighbour);
            }
        }
    
       if(topo.size()==V) return topo;
       return {};
    }
};
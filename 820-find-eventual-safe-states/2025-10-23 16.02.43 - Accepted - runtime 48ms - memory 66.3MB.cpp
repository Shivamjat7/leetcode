class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        for(int node =0;node<V;node++){
            for(int neighbour:graph[node] ){
                adj[neighbour].push_back(node);
            }
        }
        vector<int> indegree(V,0);
        for(int i =0;i<V;i++){
            for(int j :adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i =0;i<V;i++){
            if(!indegree[i])q.push(i);
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            safeNodes.push_back(node);
            for(int neighbour:adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0)q.push(neighbour);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
        
    }
};
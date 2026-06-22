class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p= succProb[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        vector<double>prob(n,0);
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto[p,node]=pq.top();
            pq.pop();
            if(p<prob[node])continue;
            for(auto [neigh,np]:adj[node]){
                if(np*p>prob[neigh]){
                    prob[neigh]=np*p;
                    pq.push({np*p,neigh});
                }
            }
        }
        return prob[end_node];

    }
};
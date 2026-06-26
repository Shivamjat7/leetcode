class Solution {
public:
    double bfs(string src,string target,unordered_map<string,vector<pair<string,double>>>&graph){
       
        queue<pair<string,double>>q;
        q.push({src,1});
        unordered_set<string>vis;
        while(!q.empty()){
            auto[node,product]=q.front();
            q.pop();
            if(node==target) return product;
            vis.insert(node);
            for(auto &[neigh,wt]:graph[node]){
                if(vis.find(neigh)==vis.end()){
                    q.push({neigh,wt*product});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>graph;
        for(int i =0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double wt = values[i];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,1.0/wt});
        }
        vector<double>ans;
        for(auto &q:queries){
            if (!graph.count(q[0]) || !graph.count(q[1])) {
    ans.push_back(-1.0);
} else {
    ans.push_back(bfs(q[0], q[1], graph));
}
        }
        return ans;
        
        
    }
};
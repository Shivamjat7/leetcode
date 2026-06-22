class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V,false);
        vector<int> color(V,-1);
        for( int i =0;i<V;i++){
            if(!visited[i]){
                if(!dfs(graph,i,visited,color))
                 return false;
            }
        }
        return true;
    }
    bool dfs (vector<vector<int>>& graph,int node,vector<bool> & visited,vector<int> & color){
        visited[node] =true;
        if(color[node]==-1) color[node]=1;
        
        for(int neighbour: graph[node] ){
            if(!visited[neighbour]){
                color[neighbour]=!color[node];
                if(!dfs(graph,neighbour,visited,color)) return false;
            }else{
                if(color[neighbour]==color[node])return false;
            }
        }
        return true;
    }
};
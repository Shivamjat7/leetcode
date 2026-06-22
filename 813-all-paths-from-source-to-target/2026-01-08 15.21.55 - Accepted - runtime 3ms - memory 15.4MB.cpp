class Solution {
public:
    vector<vector<int>> ans;
    vector<int>temp;
    void f(int node,vector<vector<int>>& graph){
        if(temp.size()>graph.size())return;
        if(temp.back()==graph.size()-1){
            ans.push_back(temp);
            return;
        }
        for(int neigh:graph[node]){
            temp.push_back(neigh);
            f(neigh,graph);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        temp.push_back(0);
        f(0,graph);
        return ans;
    }
};
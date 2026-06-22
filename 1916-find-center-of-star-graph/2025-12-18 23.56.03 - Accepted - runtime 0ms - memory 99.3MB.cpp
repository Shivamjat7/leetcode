class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int>st;
        for(auto edge:edges){
            int v=edge[1];
            if(st.count(v)) return v;
            else st.insert(v);
        }
        return 1;
    }
};
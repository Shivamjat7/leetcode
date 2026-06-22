class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st(friends.begin(),friends.end());
        vector<int> ans;
        for(int id: order){
            if(st.find(id)!=st.end())ans.push_back(id);
        }
        return ans;
    }
};
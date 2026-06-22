class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;
        for(auto num:nums)st.insert(num);
        while(st.find(original )!=st.end()) original*=2;
        return original;}
        };
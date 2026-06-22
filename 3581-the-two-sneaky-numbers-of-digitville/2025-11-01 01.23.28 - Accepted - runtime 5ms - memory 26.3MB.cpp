class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int> ans;
        for(int num :nums){
            if(mp.find(num)!=mp.end()) ans.push_back(num);
            mp[num]++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        for(auto num:arr)mp[num]=0;
        int r =1;
        for(auto [num,rank]:mp){
            mp[num]=r++;
        }
        vector<int>ans;
        for(int num:arr){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};
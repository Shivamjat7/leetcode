class Solution {
public:
    int countLength(unsigned long long  num,unordered_map<int,int>&mp){
        if(num==1)return 0;
        if(num >1e9 || mp.find(num*num)==mp.end()) return 1;
        if(mp[num]>=2) return 2+countLength(num*num,mp);
        return 1;

    }
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums)mp[num]++;
        int ans =mp[1]>0?(mp[1]%2==1?mp[1]:mp[1]-1):0;
        for(int num:nums){
            if(num==1)continue;
            ans = max(ans,countLength(num,mp));
        }
        return ans;
    }
};
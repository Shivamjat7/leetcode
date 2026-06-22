class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>pref(mx+1,0);
        for(int num:nums)pref[num]++;
        for(int i=1;i<=mx;i++){
            pref[i]+=pref[i-1];
        }
        for(int i =0;i<nums.size();i++){
            nums[i]= nums[i]!=0?pref[nums[i]-1]:0;
        }
        return   nums;
        
    }
};
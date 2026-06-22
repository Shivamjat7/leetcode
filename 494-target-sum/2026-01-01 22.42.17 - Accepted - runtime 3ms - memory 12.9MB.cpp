class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(int x :nums) sum+=x;
        if(sum-target<0||(sum - target)%2)return 0;
        int tar=(sum-target)/2;
        vector<int>prev(tar+1,0),curr(tar+1,0);
        if(nums[0]==0 )prev[0]=2;
        else prev[0]=1;
        if(nums[0]!=0 && nums[0]<=tar) prev[nums[0]]=1;
        for(int i =1;i<nums.size();i++){
            for(int t =0;t<=tar;t++){
                int notTake = prev[t];
                int take =0;
                if(nums[i]<=t) take = prev[t-nums[i]];
                curr[t]=take+notTake;
            }
            prev = curr;
        }
        return prev[tar];
    }
};
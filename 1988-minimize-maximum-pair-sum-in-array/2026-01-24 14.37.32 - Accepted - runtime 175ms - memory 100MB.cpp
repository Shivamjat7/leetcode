class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int pSum=0;
        int n =nums.size();
        for(int i =0;i<n/2;i++){
            int sm = nums[i]+nums[n-1-i];
            pSum=max(pSum,sm);
        }
        return pSum;
    }
};
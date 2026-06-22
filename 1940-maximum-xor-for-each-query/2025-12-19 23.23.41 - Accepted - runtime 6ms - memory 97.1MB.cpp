class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x =0;
        int n = nums.size();
        for(int num: nums) x^=num;
        vector<int> ans(nums.size());
        int max=(1<<maximumBit)-1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[n-1-i]=x^max;
            x=x^nums[i];
        }
        return ans;
    }
};
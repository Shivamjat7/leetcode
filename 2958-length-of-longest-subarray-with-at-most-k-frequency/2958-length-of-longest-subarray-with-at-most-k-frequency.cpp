class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans =0;
        unordered_map<int,int>window;
        int left =0;
        int right =0;
        while(right<nums.size()){
            window[nums[right]]++;
            while(window[nums[right]]>k){
                window[nums[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
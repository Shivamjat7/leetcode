class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN, currentSum =0;
        for(int val:nums){
            currentSum += val;
            if(currentSum>maxSum) maxSum=currentSum;
            if(currentSum<0) currentSum=0;
        }
        return maxSum;
        
    }
};
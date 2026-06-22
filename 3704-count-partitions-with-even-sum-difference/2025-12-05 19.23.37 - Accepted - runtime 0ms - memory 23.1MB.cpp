class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n,0);
        prefixSum [0]=nums[0];
        for(int i =1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        int cnt=0;
        for(int i =0;i<n-1;i++){
            int diff =  (prefixSum[i]-(prefixSum[n-1]-prefixSum[i]));
            if(diff%2==0)cnt++;
        }
        return cnt;

    }
};
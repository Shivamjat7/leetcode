class Solution {
public:
 
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1),parent(n,-1);
        int mxLen =1,lastIndex=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&& dp[j]>=dp[i]){
                    dp[i]=1+dp[j];
                    parent[i]=j;
                }
            }
            if(dp[i]>mxLen){
                lastIndex =i;
                mxLen = dp[i];
            }
        }
        
        vector<int>ans;
        while(lastIndex!=-1){
            ans.push_back(nums[lastIndex]);
            lastIndex=parent[lastIndex];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
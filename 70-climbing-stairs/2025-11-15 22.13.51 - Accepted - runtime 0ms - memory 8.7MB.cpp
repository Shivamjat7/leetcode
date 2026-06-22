class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return numOfWays(n,dp);

        
    }
    int numOfWays(int n,vector<int>&dp){
        if(n==0||n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        dp[n]=numOfWays(n-1,dp)+numOfWays(n-2,dp);
        return dp[n];
    }
    
};


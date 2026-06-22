class Solution {
public:
    int f(vector<int>& coins,int amount,vector<int>&dp){
        if(amount==0)return 0;
        if(amount<0)return 1e9;
        if(dp[amount]!=1e9)return dp[amount];
        int minCoin=INT_MAX;
        for(int coin :coins){
            minCoin= min(minCoin,f(coins,amount-coin,dp));
        }
        return dp[amount]=minCoin+1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e9);
        int ans =f(coins,amount,dp);
        return ans>=1e9?-1:ans;
    }
};
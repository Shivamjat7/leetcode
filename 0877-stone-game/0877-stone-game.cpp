class Solution {
public:
    long total =0;
    int n ;
    bool solve(int i,int sum ,vector<int>&piles,vector<vector<int>>&dp){
        if(i==n/2){
            if(sum>(total-sum))return 1;
            return 0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        return dp[i][sum]=solve(i+1,sum+piles[i],piles,dp)||solve(i+1,sum+piles[n-1-i],piles,dp);
    }
    bool stoneGame(vector<int>& piles) {
        total = accumulate(piles.begin(),piles.end(),0ll);
        n=piles.size();
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return solve(0,0,piles,dp);
    }
};
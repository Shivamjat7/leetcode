class Solution {
public:
    int count(int start,int end,vector<vector<int>>&dp){
        if(start>end)return 1;
        if(dp[start][end]!=-1)return dp[start][end];
        int cnt =0;
        for(int i=start;i<=end;i++ ){
            cnt+=count(start,i-1,dp)*count(i+1,end,dp);
        }
        return dp[start][end]= cnt;
    }
    int numTrees(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return count(1,n,dp);
    }
};
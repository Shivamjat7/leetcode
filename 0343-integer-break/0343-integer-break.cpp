class Solution {
public:
 
    int integerBreak(int n) {
        vector<int>dp(n+1,0);
        dp[1]=1;
        dp[2]=1;
        for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            int num1 = max(j,dp[j]);
            int num2 = max(i-j,dp[i-j]);
            dp[i]=max(dp[i],num1*num2);
        }
        }
        return dp[n];
    }
};
class Solution {
public:
  
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        sort(pairs.begin(),pairs.end());
        for(int i=1;i<=n;i++ ){
            for(int j=0;j<=n;j++){
                int notTake =dp[i-1][j];
                int take =0;
                if(j==0||pairs[i-1][1]<pairs[j-1][0]) take =1+dp[i-1][i];
                dp[i][j]=max(notTake,take);
            }
        }

        return dp[n][0];
    }
};
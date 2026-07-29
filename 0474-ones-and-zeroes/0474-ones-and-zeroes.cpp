class Solution {
public:
    
    int find(int i,int m,int n,vector<string>&strs,vector<vector<vector<int>>>&dp){
      if(i<0)return 0;
      if(dp[i][m][n]!=-1)return dp[i][m][n];
        int notTake = find(i-1,m,n,strs,dp);
        int take =0;
         int one=0;
            int zero=0;
            for(char ch:strs[i]){
                if(ch=='1')one++;
                else zero++;
            }
        if(one<=n && zero<=m)take =1+ find(i-1,m-zero,n-one,strs,dp);
        return dp[i][m][n]= max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>>dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return find(strs.size()-1,m,n,strs,dp);
        
    }
};
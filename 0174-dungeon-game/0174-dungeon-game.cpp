class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m =dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int x =dungeon[n-1][m-1];
        dp[n-1][m-1]=x>=0?1:1-x;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1&&j==m-1)continue;
                 int right = j<m-1?dp[i][j+1]:1e8;
                 int down = i<n-1?dp[i+1][j]:1e8;
                 int need=min(right,down);
                 dp[i][j]=max(1,need-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
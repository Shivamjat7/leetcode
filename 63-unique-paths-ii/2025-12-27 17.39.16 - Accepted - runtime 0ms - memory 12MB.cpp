class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int flag=0;
        for(int i=0;i<m;i++){
            if(grid[i][0]) flag =1;
            if(!flag){
                dp[i][0]=1;
            }else dp[i][0]=0;
        }
        flag=0;
        for(int i=0;i<n;i++){
            if(grid[0][i]) flag =1;
            if(!flag){
                dp[0][i]=1;
            }else dp[0][i]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j])dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
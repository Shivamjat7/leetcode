class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0]=grid[0];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int mnCost = INT_MAX;
                for(int k=0;k<n;k++){
                    int x =grid[i-1][k];
                    int cost = moveCost[x][j]+dp[i-1][k];
                    mnCost=min(cost,mnCost);
                }
                dp[i][j]=mnCost+grid[i][j];
            }
        }
        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};
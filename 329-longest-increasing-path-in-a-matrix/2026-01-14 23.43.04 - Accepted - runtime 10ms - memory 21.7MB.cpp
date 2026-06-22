class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int m ,n;
    int f(int i, int j ,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        int longest =1;
        
        for(int k=0;k<4;k++){
            int r =i+dy[k];
            int c=j+dx[k];
            if(r>=0 && r<m && c>=0 && c<n && matrix[r][c]>matrix[i][j]){
                longest = max(longest,1+f(r,c,matrix,dp));
            }
        }
        return dp[i][j]=longest;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int longest =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    longest= max(longest,f(i,j,matrix,dp));
                }
            }
        }
        return longest;
    }
};
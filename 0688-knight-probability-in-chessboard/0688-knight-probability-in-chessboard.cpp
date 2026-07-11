class Solution {
public:
    int dr[8] ={-1,-2,-2,-1,1,2,2,1};
    int dc[8] ={-2,-1,1,2,2,1,-1,-2};
    double f(int r,int c, int k,int n,vector<vector<vector<double>>>&dp){
        if(r<0 ||r>=n ||c<0 ||c>=n ||k<0)return 0;
        if(k==0)return 1;
        if( dp[r][c][k]!=-1)return dp[r][c][k];
        double prob =0;
        for(int i=0;i<8;i++){
            prob+=f(r+dr[i],c+dc[i],k-1,n,dp);
        }
        return dp[r][c][k]= prob*(1.0/8);

    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return f(row,column,k,n,dp);
    }
};
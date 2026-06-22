class Solution {
public:
    int mx=0;
    int sum =0;
    int n,m;
    void f(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        if(i<0 || i>=n ||j<0 ||j>=m)return;
        if(grid[i][j]==0 || vis[i][j]){
            return;
        }
        
        sum+=grid[i][j];
        vis[i][j]=true;
       mx = max(sum,mx);
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        for(int k =0;k<4;k++){
            int r = i+dr[k];
            int c = j+dc[k];
            f(r,c,grid,vis);
            
        }
        sum-=grid[i][j];
        vis[i][j]=false;
        
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
         n =grid.size();
         m =grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    f(i,j,grid,vis);
                    
                }
            }
        }
        return mx;
    }
};
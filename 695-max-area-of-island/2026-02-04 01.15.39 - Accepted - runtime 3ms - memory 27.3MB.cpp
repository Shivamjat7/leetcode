class Solution {
public:
    int delRow[4]={0,-1,0,1};
    int delCol[4]={-1,0,1,0};
    int m,n;
    int dfs(int i,int j,vector<vector<int>>& grid){
        int cnt =1;
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int r = i+delRow[k];
            int c = j+ delCol[k];
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c]){
                cnt+=dfs(r,c,grid);
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int mx=0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    mx = max(mx,dfs(i,j,grid));
                }
            }
        }
        return mx;
    }
};
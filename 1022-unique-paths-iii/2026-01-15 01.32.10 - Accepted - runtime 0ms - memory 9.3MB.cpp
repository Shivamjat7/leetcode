class Solution {
public:
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    int n,m;
    int cnt =0;
    void f(int i,int j,vector<vector<int>>&grid,int remain){
        if(grid[i][j]==2 ){
          if(remain==0)  cnt++ ;
            return ;
        }
        int temp=grid[i][j];
        grid[i][j]=-1;
        for(int k =0;k<4;k++){
            int r = i+dx[k];
            int c = j+dy[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]!=-1){
        
                f(r,c,grid,remain-1);
                
            }
        }grid[i][j]=temp;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m =grid[0].size();
        int remain=0;
        pair<int,int>p;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)remain++;
                if(grid[i][j]==1)p={i,j};
            }
        }
        f(p.first,p.second,grid,remain+1);
       
        return cnt;
    }
};
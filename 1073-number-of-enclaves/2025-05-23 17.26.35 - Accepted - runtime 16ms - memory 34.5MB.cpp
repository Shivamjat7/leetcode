class Solution {
private:
    void dfs(pair<int,int> node,vector<vector<int>> & grid, vector<vector<bool>> & visited){
        int r= node.first;
        int c= node.second;
        visited[r][c]=true;
        int n= grid.size();
        int m= grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int row = r+delrow[i];
            int col = c+delcol[i];
            if( row>=0 && row<n && col>=0 && col<m){
                if( grid[row][col]==1 && !visited[row][col]){
                    dfs( {row,col},grid,visited);
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            if(grid[i][0] && !visited[i][0]) dfs({i,0},grid,visited);
            if(grid[i][m-1] && !visited[i][m-1]) dfs({i,m-1},grid,visited);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j] && !visited[0][j]) dfs({0,j},grid,visited);
            if(grid[n-1][j] && !visited[n-1][j]) dfs({n-1,j},grid,visited);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]) cnt++;
            }
        }
    return cnt;
        
    }
};
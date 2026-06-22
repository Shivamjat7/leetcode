class Solution {
    void bfs(pair<int,int>p ,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        auto[i,j]=p;
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]='0';
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();

            int delRow[] ={-1,0,1,0};
            int delCol[] ={0,1,0,-1};
            for(int it =0;it<4;it++){
              int nRow = r+delRow[it] ;
              int nCol = c+ delCol[it];
              if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]=='1') {
               grid[nRow][nCol]='0';
                q.push({nRow,nCol});
              }
            }

        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long cnt =0;
       
       for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                cnt++;
                bfs({i,j},grid);
            }
        }
       }
return cnt;
    }
};
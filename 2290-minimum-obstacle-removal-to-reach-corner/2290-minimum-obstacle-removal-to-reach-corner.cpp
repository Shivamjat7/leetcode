class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        pq.push({grid[0][0],{0,0}});
        int delRow[] ={-1,0,1,0};
        int delCol[] ={0,1,0,-1};
        while(!pq.empty()){
            int dst = pq.top().first;
            int i =pq.top().second.first;
            int j =pq.top().second.second;
            pq.pop();
            if(dst>dist[i][j])continue;
            for(int k =0;k<4;k++){
                int row =i+delRow[k];
                int col =j+delCol[k];
                if(row>=0 && row<m && col>=0 && col<n){
                    if(grid[row][col]+dst<dist[row][col]){
                        dist[row][col]=dst+grid[row][col];
                        pq.push({dst+grid[row][col],{row,col}});
                    }
                }
            }

        }
        return dist[m-1][n-1];
    }
};
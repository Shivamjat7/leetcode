class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int m = grid.size();
        int n = grid[0].size();
        int dr[] ={-1,0,1,0};
        int dc[] ={0,1,0,-1};
        pq.push({health-grid[0][0],{0,0}});
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int h = it.first;
            auto [row,col]=it.second;
            if(h<=0 || grid[row][col]==2)continue;
            grid[row][col]=2;
            if(row==m-1 && col ==n-1 && h>=1)return true;
            for(int i=0;i<4;i++){
                int r =row+ dr[i];
                int c = col+dc[i];
                if(r>=0 && r<m && c>=0 && c<n && grid[r][c]!=2){
                    pq.push({h-grid[r][c],{r,c}});
                }
            }

        }
        return false;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==0)
            q.push({0,{0,0}});
            
        dist[0][0]=0;
        while(!q.empty()){
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0&&j==0) continue;
                    int r=row+i;
                    int c=col+j;
                    if(row==n-1 && col==n-1) return d+1;
                    if(r>=0 && r<n && c>=0 && c<n &&
                        grid[r][c]==0 && d+1<dist[r][c]){
                            dist[r][c]=d+1;
                            q.push({d+1,{r,c}});
                        }
                }
            }
            
        }

      return -1;  
    }
};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n= grid.size();
        int m =grid[0].size();
        int perimeter=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    for(int k=0;k<4;k++){
                        int row = i+delr[k];
                        int col = j+delc[k];
                        if(row<0 || row>=n || col<0 || col>=m ||!grid[row][col]) perimeter++;
                    }
                }
            }
        }
        return perimeter;
    }
};
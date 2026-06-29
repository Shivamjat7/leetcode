class Solution {
public:
    int n;
    int delRow[4]={-1,0,1,0};
    int delCol[4]={0,1,0,-1};
    int id=2;
    
    void area(int row,int col,vector<vector<int>>& grid,int& islandArea){
        if(row<0 || row>=n ||col<0 ||col>=n||grid[row][col]!=1)return;
        islandArea++; 
        grid[row][col]=id;

        for(int i=0;i<4;i++){
            int r = row+delRow[i];
            int c = col+delCol[i];
            if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==1){
                area(r,c,grid,islandArea);
            }
        }

    }
    int largestIsland(vector<vector<int>>& grid) {
         n = grid.size();
        int maxArea =0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int isLandArea=0;
                    area(i,j,grid,isLandArea);
                    mp[id]=isLandArea;
                    maxArea=max(maxArea,isLandArea);
                    id++;
                
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int ar=1;
                    unordered_set<int>st;
                      for(int k=0;k<4;k++){
                        int r = i+delRow[k];
                        int c = j+delCol[k];
                        if(r>=0 && r<n && c>=0 && c<n && grid[r][c]>1&& !st.count(grid[r][c]) ){
                            st.insert(grid[r][c]);
                         ar+=mp[grid[r][c]];
                         }
                     }
                     maxArea = max(ar,maxArea);

                }
            }
        }
        return maxArea;

    }
};
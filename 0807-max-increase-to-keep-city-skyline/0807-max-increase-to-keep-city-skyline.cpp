class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<int>col(n,0),row(n,0);
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                int ht=grid[i][j];
                col[j]=max(col[j],ht);
                row[i]=max(row[i],ht);
            }
        }
        int total =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int mx=min(row[i],col[j]);
                total+= mx-grid[i][j];
            }
        }
        return total;
    }
};
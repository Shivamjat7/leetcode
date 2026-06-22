class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int>>diff(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]) cnt++;
                else cnt--;
            }
            for(int j =0;j<m;j++) diff[i][j]+=cnt;
        }
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]) cnt++;
                else cnt--;
            }
            for(int i =0;i<n;i++) diff[i][j]+=cnt;
        }
        return diff;
    }
};
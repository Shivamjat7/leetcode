class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> local(n - 2, vector<int>(n - 2));

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                int mx = 0;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        mx = max(mx, grid[x][y]);
                    }
                }
                local[i][j] = mx;
            }
        }
        return local;
    }
};

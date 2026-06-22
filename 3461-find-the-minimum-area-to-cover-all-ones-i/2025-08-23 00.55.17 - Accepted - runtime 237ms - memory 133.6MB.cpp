class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minR = INT_MAX, minC = INT_MAX, maxR = -1, maxC = -1;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    minR = min(minR, i);
                    minC = min(minC, j);
                    maxR = max(maxR, i);
                    maxC = max(maxC, j);
                }

        if (maxR == -1) return 0;                   // no 1s present (defensive)
        return (maxR - minR + 1) * (maxC - minC + 1);
    }
};

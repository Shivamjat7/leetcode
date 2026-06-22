class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> row(n, vector<int>(m + 1, 0));
        vector<vector<int>> col(n + 1, vector<int>(m, 0));

        // Prefix sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        // Try largest size first
        for (int sz = min(n, m); sz >= 2; sz--) {
            for (int i = 0; i + sz <= n; i++) {
                for (int j = 0; j + sz <= m; j++) {

                    int target = row[i][j + sz] - row[i][j];
                    bool ok = true;

                    // Check rows
                    for (int r = i; r < i + sz; r++) {
                        if (row[r][j + sz] - row[r][j] != target) {
                            ok = false;
                            break;
                        }
                    }

                    // Check columns
                    for (int c = j; c < j + sz && ok; c++) {
                        if (col[i + sz][c] - col[i][c] != target) {
                            ok = false;
                            break;
                        }
                    }

                    // Check diagonals
                    int d1 = 0, d2 = 0;
                    for (int k = 0; k < sz; k++) {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + sz - 1 - k];
                    }

                    if (ok && d1 == target && d2 == target)
                        return sz;
                }
            }
        }

        return 1;
    }
};

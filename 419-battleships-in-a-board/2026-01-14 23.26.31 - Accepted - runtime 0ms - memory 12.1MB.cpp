class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int i, int j, vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // boundary + visited + invalid check
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '.')
        return;

    grid[i][j] = '.';   // mark visited

    for (int d = 0; d < 4; d++) {
        dfs(i + dx[d], j + dy[d], grid);
    }
}

    int countBattleships(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                count++;
                dfs(i, j, grid);
            }
        }
    }
    return count;
    }
};
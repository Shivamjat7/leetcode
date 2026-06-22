class Solution {
public:
    void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool inc) {
        int n = grid.size();
        vector<int> diag;

        int i = r, j = c;
        while (i < n && j < n) {
            diag.push_back(grid[i][j]);
            i++; j++;
        }

        if (inc)
            sort(diag.begin(), diag.end());              // ascending
        else
            sort(diag.begin(), diag.end(), greater<int>()); // descending

        i = r; j = c;
        int idx = 0;
        while (i < n && j < n) {
            grid[i][j] = diag[idx++];
            i++; j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Lower-left diagonals (descending)
        for (int i = 0; i < n; i++) {
            sortDiagonal(i, 0, grid, false);
        }

        // Upper-right diagonals (ascending)
        for (int j = 1; j < n; j++) {
            sortDiagonal(0, j, grid, true);
        }

        return grid;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int r = grid.size();
        int c = grid[0].size();

        grid[row][col] = '0';
        if (row - 1 >= 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col);
        if (col - 1 >= 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1);
        if (row + 1 < r && grid[row + 1][col] == '1') dfs(grid, row + 1, col);
        if (col + 1 < c && grid[row][col + 1] == '1') dfs(grid, row, col + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>&grid, int ROWS, int COLS){
        int area = 1;
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] == 0) return 0;
        //mark visited
        grid[row][col] = 0;
        for (auto& [dr, dc] : dirs) {
            int newR = dr + row, newC = dc + col;
            area += dfs(newR, newC, grid, ROWS, COLS);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;

        int res = 0;
        int ROWS = grid.size(), COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (grid[r][c] == 1){
                    int tmp = dfs(r, c, grid, ROWS, COLS);
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};

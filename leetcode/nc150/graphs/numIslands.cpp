class Solution {
public:


void dfs(int row, int col, vector<vector<char>>& grid, int ROWS, int COLS){
    vector<pair<int,int>>dirs = {{1,0},{0,1},{-1,0},{0,-1}};

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] == '0') return;

    //mark visited
    grid[row][col] = '0';

    for (auto& [dr, dc] : dirs){
        int newR = row + dr, newC = col + dc;
        dfs(newR, newC, grid, ROWS, COLS);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;

        int res = 0;
        int ROWS = grid.size(), COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (grid[r][c] == '1'){
                    dfs(r, c, grid, ROWS, COLS);
                    res++;
                }
            }
        }

        return res;

        
    }
};

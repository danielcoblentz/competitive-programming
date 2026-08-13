#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using std::vector;
using std::queue;
using std::pair;
using std::min;


// distance from every cell to its nearest source, walls are -1, sources are 0
// time: O(ROWS * COLS), space: O(ROWS * COLS) for the queue
void multiSrcBfs(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return;

    int ROWS = grid.size(), COLS = grid[0].size();
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // every source enters at level 0, so one wave leaves all of them together
    queue<pair<int, int>> q;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == 0) q.push({r,c});
        }
    }

    while (q.size()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for (auto& [dr, dc] : dirs) {
            int newR = r + dr, newC = c + dc;
            // a value other than INT_MAX is a wall, a source, or a finished cell
            if (min(newR, newC) < 0 || newR == ROWS || newC == COLS
                || grid[newR][newC] != INT_MAX) {
                continue;
            }
            grid[newR][newC] = grid[r][c] + 1;
            q.push({newR, newC});
        }
    }
}

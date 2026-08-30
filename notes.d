functions
put const if we do not plan on modifying hte array or varible in hte functions
good for reading from arrays or strings

we inclaude hte & synbol because thso passes hte origional (pass by refrence) so anythign doe to it here will affect the origional
if not it makes a copy and does some operation to it, especially for backtraxking we need hte origional


grid bfs, the shape to reuse

int ROWS = grid.size(), COLS = grid[0].size();
vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pair<int, int>> q;

// seed, push every source before the loop starts so they all sit at level 0
for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
        if (isSource(grid[r][c])) q.push({r, c});
    }
}

while (q.size()) {
    int size = q.size();          // only if each level is a step, a minute, a distance
    for (int i = 0; i < size; i++) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for (auto& [dr, dc] : dirs) {
            int newR = r + dr, newC = c + dc;
            if (min(newR, newC) < 0 || newR == ROWS || newC == COLS || <problem test>) continue;
            mark(newR, newC);     // mark, count, push, all at the same time
            q.push({newR, newC});
        }
    }
    steps++;
}

the guard is always the same 3 bounds clauses, only the last one changes
min(newR, newC) < 0 is just newR < 0 || newC < 0
last clause answers, is this cell off limits or already handled
  islands and treasure   grid[newR][newC] != INT_MAX
  rotting oranges        grid[newR][newC] != 1
  separate visit array   visit[newR][newC] || grid[newR][newC] == 1

use the grid itself as the visited set when it can hold the answer, that kills the visit array
add visit only when the input has to stay intact or the old values are needed later

always mark and count a cell when you push it, never when you pop it
if you mark on pop the same cell gets pushed twice by two neighbors in the same level
if you count on pop the counter lags a level and the step count comes out one too high

cache int size = q.size() before the inner loop when the answer is a number of levels
skip the level loop when you only need a distance per cell, store it in the grid instead
grid[newR][newC] = grid[r][c] + 1 carries the distance, so nothing extra goes in the queue

multi source is the same code, the seed loop just pushes more than one cell
never push a source after the loop has started, its wave would be measured from the wrong place
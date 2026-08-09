# Style cheatsheet

How code in this repo is named and written. Everything below is taken from the files in
`templates/`; the file named in each row is the one to copy from.

## File scaffolding

**Template / library file**: no `main`, narrow includes, one `using std::` line per name:

```cpp
#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::queue;
using std::min;
```

**Contest solution**: one header, one namespace, `ll` typedef, `solve()` per test case:

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve() {
    ...
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

Use `ll` everywhere once it is typedef'd: parameters, locals, return types, casts `(ll)x`.
Never spell out `long long` in the body.

## Names

| Thing | Convention | Examples |
|---|---|---|
| Function | camelCase, verb-ish | `shortestPath`, `rangeQuery`, `unionSets`, `optimizedDp` |
| Recursive helper | base name + `Helper`, or plain `helper` | `dfs` / `dfsHelper`, `memoization` / `memoHelper`, `helper2` |
| Class | PascalCase | `SegmentTree`, `UnionFind`, `TreeNode` |
| Class field | trailing underscore | `sum_`, `left_`, `right_`, `L_`, `par_`, `rank_`, `val_` |
| Dimension / size | ALL CAPS | `ROWS`, `COLS`, `N`, `M` |
| Constant | ALL CAPS | `MOD`, `MAXN` |
| Everything else | short and conventional | see below |

Locals stay short. Write `curSum`, not `currentRunningSum`; write `w`, not `blackCellCount`.

- window / binary search bounds: `L`, `R`, `M` (`mid` also fine)
- grid coordinates: `r`, `c`, and `newR`, `newC` for a neighbor
- loop index: `i`, `j`; second dimension in a DP: `c` for capacity, `i` for item
- pairs of related values: `p1`/`p2`, `n1`/`n2`, `w1`/`w2`, `a`/`b`/`c`
- running values: `cur`/`max`/`min` prefix, `curSum`, `curSet`, `curRow`, `maxSum`, `maxProfit`
- containers by role: `adj`, `dp`, `cache`, `visit`, `nums`, `grid`, `res`, `seen`
- `res` is the returned answer, `count`/`total`/`length` for accumulators

## Loops

Index loop, `size()` compared directly, no cached `n`:

```cpp
for (int R = 0; R < nums.size(); R++) {
```

Range-for when the element is used whole (`sliding-window-var.cpp`, `dijkstras.cpp`):

```cpp
for (vector<int> edge : edges) {
    int s = edge[0], d = edge[1], w = edge[2];
```

Two pointers: `L` fixed at 0, `R` drives the loop, `L` advances inside a `while`:

```cpp
int L = 0;
for (int R = 0; R < nums.size(); R++) {
    total += nums[R];
    while (total >= target) {
        length = min(R - L + 1, length);
        total -= nums[L];
        L++;
    }
}
```

Grid neighbors are written out as a literal, not a `dirs` array (`matrix_bfs.cpp`):

```cpp
int neighbors[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};
for (int j = 0; j < 4; j++) {
    int newR = neighbors[j][0], newC = neighbors[j][1];
    if (min(newR, newC) < 0 || newR == ROWS || newC == COLS
        || visit[newR][newC] || grid[newR][newC]) {
        continue;
    }
    ...
}
```

Level-order BFS caches the level size first:

```cpp
while (queue.size()) {
    int queueLength = queue.size();
    for (int i = 0; i < queueLength; i++) {
        ...
    }
    length++;
}
```

## Recursive functions and their parameters

Parameter order is **index first, inputs next, mutable state last**:

```cpp
// templates/backtracking/subsets.cpp
void helper(int i, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& subsets)

// templates/DP/bottom_up/knapsack_0_1.cpp
int memoHelper(int i, vector<int>& profit, vector<int>& weight, int capacity,
    vector<vector<int>>& cache)
```

- Containers are always passed by reference (`vector<int>& nums`), `const` only when the
  function never writes to it (`matrix_dfs.cpp`).
- Accumulators and memo tables are trailing out-parameters, not return values, when the
  recursion is a fan-out (`subsets`, `cache`).
- A grid DFS takes the grid, then `r`, `c`, then `visit`:
  `int dfs(const vector<vector<int>>& grid, int r, int c, vector<vector<int>>& visit)`.
- Guard clauses first, one `if` per bail-out reason, then the recursion, then undo:

```cpp
if (i >= nums.size()) {
    subsets.push_back(vector<int>(curSet));
    return;
}
curSet.push_back(nums[i]);
helper(i + 1, nums, curSet, subsets);
curSet.pop_back();
```

- Public wrapper stays clean and calls the helper with the seed values:

```cpp
vector<vector<int>> subsetsWithoutDuplicates(vector<int>& nums) {
    vector<int> curSet;
    vector<vector<int>> subsets;
    helper(0, nums, curSet, subsets);
    return subsets;
}
```

## Classes

```cpp
class UnionFind {
public:
    unordered_map<int, int> par_;
    unordered_map<int, int> rank_;

    UnionFind(int n) { ... }

    int find(int x) { ... }
};
```

Members public, trailing underscore, constructor assigns in the body (not an init list).
Tree-shaped structures use a `static build(...)` factory returning a raw pointer
(`segment-tree.cpp`).

## Formatting

- 4-space indent, opening brace on the same line, `} else {` on one line.
- Braces on `if` bodies; a one-line early return (`if (n == 0) return -1;`) is fine.
- Multiple related declarations on one line: `int L = 0, total = 0;`, `int ROWS = grid.size(), COLS = grid[0].size();`
- Blank line between logical sections of a function.

## Comments

**No capital letters, no periods, no em dashes in a comment.** Use a comma or a colon
instead. This covers the first word and proper nouns too:

```cpp
// decision to include nums[i]
// we can directly build the four neighbors
// s[i] is i + 1, so an even (blue) sits at odd i
// fill the first column and row to reduce edge cases
```

- `//` notes above a block, saying *why*, in plain language.
- Complexity above alternative implementations, followed by what the letters mean:

```cpp
// memoization solution
// time: O(n * m), space: O(n * m)
// where n is the number of items and m is the capacity
```

- Note the gotcha where it bites: `// union is a reserved keyword in c++, so the method
  has to be named something else`
- No banner comments, no restating the problem statement, no multi-paragraph derivations at
  the top of a solution file. Explain the reasoning in chat instead.

Files already under `templates/` predate this rule and still have capitals and periods in
their comments; follow the rule for anything new rather than reformatting them.

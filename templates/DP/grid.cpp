#include <vector>

using std::vector;

int dfsHelper(int i, int j) {
    if (i == 0 || j == 0) return 1;
    return dfsHelper(i - 1, j) + dfsHelper(i, j - 1);
}

int dfs(int m, int n) {
    return dfsHelper(m - 1, n - 1);
}

int memoHelper(int i, int j, vector<vector<int>>& cache) {
    if (i == 0 || j == 0) return 1;
    if (cache[i][j] != -1) return cache[i][j];
    cache[i][j] = memoHelper(i - 1, j, cache) + memoHelper(i, j - 1, cache);
    return cache[i][j];
}

int memoization(int m, int n) {
    vector<vector<int>> cache(m, vector<int>(n, -1));
    return memoHelper(m - 1, n - 1, cache);
}

int dp(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int optimizedDp(int m, int n) {
    vector<int> prv(n, 1);
    for (int i = 1; i < m; i++) {
        vector<int> cur(n, 0);
        cur[0] = 1;
        for (int j = 1; j < n; j++) {
            cur[j] = prv[j] + cur[j - 1];
        }
        prv = cur;
    }
    return prv[n - 1];
}

int oneRowDp(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

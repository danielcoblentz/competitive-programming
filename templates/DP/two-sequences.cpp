#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::max;

int dfsHelper(int i, int j, string& first, string& second) {
    if (i == 0 || j == 0) return 0;
    if (first[i - 1] == second[j - 1]) {
        return dfsHelper(i - 1, j - 1, first, second) + 1;
    }
    return max(dfsHelper(i - 1, j, first, second), dfsHelper(i, j - 1, first, second));
}

int dfs(string& first, string& second) {
    return dfsHelper(first.size(), second.size(), first, second);
}

int memoHelper(int i, int j, string& first, string& second,
    vector<vector<int>>& cache) {
    if (i == 0 || j == 0) return 0;
    if (cache[i][j] != -1) return cache[i][j];
    if (first[i - 1] == second[j - 1]) {
        cache[i][j] = memoHelper(i - 1, j - 1, first, second, cache) + 1;
    } else {
        cache[i][j] = max(memoHelper(i - 1, j, first, second, cache),
            memoHelper(i, j - 1, first, second, cache));
    }
    return cache[i][j];
}

int memoization(string& first, string& second) {
    int m = first.size() + 1, n = second.size() + 1;
    vector<vector<int>> cache(m, vector<int>(n, -1));
    return memoHelper(first.size(), second.size(), first, second, cache);
}

int dp(string& first, string& second) {
    int m = first.size() + 1, n = second.size() + 1;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m - 1][n - 1];
}

int optimizedDp(string& first, string& second) {
    int m = first.size() + 1, n = second.size() + 1;
    vector<int> prv(n, 0);

    for (int i = 1; i < m; i++) {
        vector<int> cur(n, 0);
        for (int j = 1; j < n; j++) {
            if (first[i - 1] == second[j - 1]) {
                cur[j] = prv[j - 1] + 1;
            } else {
                cur[j] = max(prv[j], cur[j - 1]);
            }
        }
        prv = cur;
    }
    return prv[n - 1];
}

int oneRowDp(string& first, string& second) {
    int m = first.size() + 1, n = second.size() + 1;
    vector<int> dp(n, 0);

    for (int i = 1; i < m; i++) {
        int diag = 0;
        for (int j = 1; j < n; j++) {
            int temp = dp[j];
            if (first[i - 1] == second[j - 1]) {
                dp[j] = diag + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            diag = temp;
        }
    }
    return dp[n - 1];
}

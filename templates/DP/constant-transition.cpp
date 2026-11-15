#include <vector>

using std::vector;

int dfs(int n) {
    if (n <= 1) return 1;
    return dfs(n - 1) + dfs(n - 2);
}

int memoHelper(int n, vector<int>& cache) {
    if (n <= 1) return 1;
    if (cache[n] != -1) return cache[n];
    cache[n] = memoHelper(n - 1, cache) + memoHelper(n - 2, cache);
    return cache[n];
}

int memoization(int n) {
    vector<int> cache(n + 1, -1);
    return memoHelper(n, cache);
}

int dp(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int optimizedDp(int n) {
    int one = 1, two = 1;
    for (int i = 2; i <= n; i++) {
        int temp = one + two;
        two = one;
        one = temp;
    }
    return one;
}

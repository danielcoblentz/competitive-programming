#include <vector>

using std::vector;

void helper(int i, vector<int>& curComb, vector<vector<int>>& combs, int n, int k) {
    if (curComb.size() == k) {
        combs.push_back(vector<int>(curComb));
        return;
    }
    if (i > n) return;

    // decision to include i
    curComb.push_back(i);
    helper(i + 1, curComb, combs, n, k);
    curComb.pop_back();

    // decision to NOT include i
    helper(i + 1, curComb, combs, n, k);
}

// Given n numbers (1 - n), return all possible combinations
// of size k. (n choose k math problem).
// Time: O(k * 2^n)
vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> combs;
    vector<int> curCombs;
    helper(1, curCombs, combs, n, k);
    return combs;
}

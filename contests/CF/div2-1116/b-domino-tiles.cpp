#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

// the tiles we can take: if the char is fixed then so is the value, otherwise both work
vector<int> tileValues(char ch) {
    if (ch == '0') return {0};
    if (ch == '1') return {1};
    return {0, 1};
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // n == 1 has no dominoes at all, and s[1] would be out of range below
    if (n == 1) {
        cout << tileValues(s[0]).size() << "\n";
        return;
    }

    ll dp[2][2] = {{0, 0}, {0, 0}}; // number of valid ways to fill

    // base case, the first two tiles
    for (int a : tileValues(s[0])) {
        for (int b : tileValues(s[1])) {
            dp[a][b] += 1;
            dp[a][b] %= MOD;
        }
    }

    // process remaining tiles
    for (int i = 2; i < n; i++) {
        // next state
        ll newDp[2][2] = {{0, 0}, {0, 0}};

        // possible pair of values for the previous two tiles
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                if (dp[a][b] == 0) continue;
                int prevW = a + b;

                for (int c : tileValues(s[i])) {
                    int newW = b + c;

                    // only valid if the new domino's weight differs from the previous one
                    if (newW != prevW) {
                        newDp[b][c] += dp[a][b];
                        newDp[b][c] %= MOD;
                    }
                }
            }
        }

        // move to the next i
        memcpy(dp, newDp, sizeof(dp));
    }

    // sum every valid ending state
    ll res = 0;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            res = (res + dp[a][b]) % MOD;
        }
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

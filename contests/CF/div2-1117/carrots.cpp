#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> cnt(m + 2, 0);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        cnt[v]++;
    }

    // gt[x] is how many carrots are longer than x
    vector<ll> gt(m + 2, 0);
    for (int x = m - 1; x >= 1; x--) gt[x] = gt[x + 1] + cnt[x + 1];

    ll res = 0;
    for (int x = 1; x <= m; x++) {
        ll cur = cnt[x] + gt[x];
        if ((ll)2 * x <= m) cur += cnt[2 * x];
        res = max(res, cur);
    }

    ll b1 = 0, b2 = 0;
    for (int v = 1; v <= m; v++) {
        if (cnt[v] > b1) {
            b2 = b1;
            b1 = cnt[v];
        } else if (cnt[v] > b2) {
            b2 = cnt[v];
        }
    }
    res = max(res, b1 + b2);

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

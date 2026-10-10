#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    ll m, k;
    cin >> n >> m >> k;

    vector<ll> l(n), r(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        pre[i + 1] = pre[i] + r[i] - l[i] + 1;
    }

    auto upTo = [&](ll x) {
        int j = upper_bound(l.begin(), l.end(), x) - l.begin();
        if (j == 0) return 0LL;
        return pre[j - 1] + min(x, r[j - 1]) - l[j - 1] + 1;
    };
    auto f = [&](ll s) {
        return upTo(s + m - 1) - upTo(s - 1);
    };

    ll hi = r[n - 1] + 1;
    if (k == 0) {
        cout << hi << endl;
        return;
    }

    ll lo = l[0];
    for (int i = 0; i < n; i++) {
        if (f(l[i]) > f(lo)) lo = l[i];
    }
    if (f(lo) < k) {
        cout << -1 << endl;
        return;
    }

    while (hi - lo > 1) {
        ll M = lo + (hi - lo) / 2;
        if (f(M) >= k) {
            lo = M;
        } else {
            hi = M;
        }
    }

    cout << lo << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

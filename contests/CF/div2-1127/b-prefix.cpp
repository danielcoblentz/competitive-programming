#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // a[0] never changes, so it is the starting answer
    ll maxSum = a[0], minSum = a[0], res = a[0];
    for (int i = 1; i < n; i++) {
        // best value here is a[i] + |prefix sum|, and the biggest |prefix sum| is one of the two extremes
        ll farthest = max(abs(maxSum), abs(minSum));
        res = max(res, a[i] + farthest);

        // the three choices turn prefix sum s into a[i], s + a[i], or 2 * s + a[i]
        ll newMax = max({a[i], maxSum + a[i], 2 * maxSum + a[i]});
        ll newMin = min({a[i], minSum + a[i], 2 * minSum + a[i]});
        maxSum = newMax;
        minSum = newMin;
    }

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

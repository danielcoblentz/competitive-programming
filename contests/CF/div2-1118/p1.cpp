#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll res = 2 * (k - 1) + (1LL << (n - k + 1));
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

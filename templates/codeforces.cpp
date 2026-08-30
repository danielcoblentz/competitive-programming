#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// a #define is plain text substitution, so unsigned ll and ll(x) will not compile,
// cast with (ll)x instead, or switch to typedef long long ll if you need those
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // if the problem is not multi test, drop the t lines and just call solve()
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

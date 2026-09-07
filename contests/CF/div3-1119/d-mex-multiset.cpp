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
    ll zeros = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) zeros++;
    }

    // with one 0 only one multiset can have a nonzero mex, so the check reads x >= 2x
    if (zeros == 1) {
        cout << "NO" << endl;
        return;
    }

    // no 0s at all leaves every mex at 0, so any assignment works
    // otherwise one 0 goes to b and the spares go to a, which keeps both mexes at 1,
    // and c never sees a 0 so its mex stays 0
    string res(n, 'C');
    int seen = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            res[i] = seen ? 'A' : 'B';
            seen++;
        }
    }

    cout << "YES" << endl;
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

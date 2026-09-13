#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<int> bad;
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) bad.pb(i);
    }

    bool ok = true;
    for (int j = 0; j < bad.size(); j++) {
        if (p[bad[j]] != bad[bad.size() - 1 - j]) ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int M = 1;
    while (M <= n) M *= 2;
    int h = M / 2;

    vector<int> p;
    for (int x = 0; x < h; x++) {
        p.pb(x);
        p.pb(x ^ h);
        p.pb(x ^ h);
        p.pb(x);
    }

    cout << p.size() - 1 << endl;
    for (int i = 1; i < p.size(); i++) cout << (p[i] ^ p[i - 1]) << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

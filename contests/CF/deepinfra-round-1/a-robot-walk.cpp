#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;

    if (b > a + 1) {
        cout << -1 << endl;
        return;
    }

    cout << ((a + b) % 2 == 0 ? a : a + 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

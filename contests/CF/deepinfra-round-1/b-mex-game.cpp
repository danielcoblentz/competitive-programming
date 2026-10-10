#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int f = 0;
    while (cnt[f] >= 2 * k) f++;

    cout << (cnt[f] == 2 * k - 1 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

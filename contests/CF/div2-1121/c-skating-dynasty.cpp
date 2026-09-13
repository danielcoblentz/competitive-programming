#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());

    // suf[i] is i * (i + 1) * ... * (n - 1), so (i - 1)! * suf[i + 1] is (n - 1)! / i
    vector<ll> suf(n + 1, 1);
    for (int i = n - 1; i >= 1; i--) suf[i] = suf[i + 1] * i % MOD;

    // pinning one parent for the i-th skater leaves (n - 1)! / i dynasties, and its i
    // candidate parents give gaps summing to pre - i * a[i]
    ll pre = 0, fact = 1, res = 0;
    for (int i = 1; i < n; i++) {
        pre = (pre + a[i - 1]) % MOD;
        ll gaps = ((pre - i * (a[i] % MOD)) % MOD + MOD) % MOD;
        res = (res + fact * suf[i + 1] % MOD * gaps) % MOD;
        fact = fact * i % MOD;
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

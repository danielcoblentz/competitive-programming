#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<ll> heap;
    ll sum = 0, res = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (heap.size() == m - 1) res = max(res, (ll)m * a[i] - sum);

        heap.push(a[i]);
        sum += a[i];
        if (heap.size() > m - 1) {
            sum -= heap.top();
            heap.pop();
        }
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

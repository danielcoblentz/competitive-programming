#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    // a known b[i] bans treasure on every island strictly closer than b[i]
    vector<int> diff(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (b[i] <= 0) continue;
        int L = max(0, i - b[i] + 1), R = min(n - 1, i + b[i] - 1);
        diff[L]++;
        diff[R + 1]--;
    }

    // whatever is left over is safe, and extra treasure never breaks a constraint,
    // so burying on every safe island is the easiest set to check
    string res(n, '0');
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += diff[i];
        if (cur == 0) res[i] = '1';
    }

    // b[i] also needs a treasure at exactly b[i], so one of the two ends must be set
    for (int i = 0; i < n; i++) {
        if (b[i] < 0) continue;
        bool ok = (i - b[i] >= 0 && res[i - b[i]] == '1')
            || (i + b[i] < n && res[i + b[i]] == '1');
        if (!ok) {
            cout << -1 << endl;
            return;
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

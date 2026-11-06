#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<bool> printed(n + 1);
    stack<int> mem;

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            mem.push(i);
        } else if (s[i - 1] == '2' && !mem.empty()) {
            // top gets printed, document i is lost
            printed[mem.top()] = true;
            mem.pop();
        } else {
            printed[i] = true;
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!printed[i]) res.pb(i);
    }

    cout << res.size() << endl;
    for (int x : res) cout << x << " ";
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

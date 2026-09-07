#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int res = 0;
    for (int i = 0; i < n; i += k) {
        bool free = false;
        for (int j = i; j < i + k; j++) {
            if (s[j] == '0') free = true;
        }
        if (!free) res++;
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

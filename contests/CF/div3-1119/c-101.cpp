#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // nxt[i] is the first fixed 1 at or after i, n if there is none
    vector<int> nxt(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = (a[i] == 1) ? i : nxt[i + 1];
    }

    // prv[i] is the last -1 at or before i, -1 if there is none
    vector<int> prv(n, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            prv[i] = i;
        } else if (i) {
            prv[i] = prv[i - 1];
        }
    }

    // the window may not contain a fixed 1 strictly inside, so for a left end i
    // the right end is either the next fixed 1, or the last -1 before it
    int best = 0, bestL = -1, bestR = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;

        int r = nxt[i + 1];
        int j = i;
        if (r < n) {
            j = r;
        } else if (prv[n - 1] > i) {
            j = prv[n - 1];
        }

        if (j - i + 1 > best) {
            best = j - i + 1;
            bestL = i;
            bestR = j;
        }
    }

    if (bestL >= 0) {
        a[bestL] = 1;
        a[bestR] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << (a[i] == -1 ? 0 : a[i]) << " ";
    }
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

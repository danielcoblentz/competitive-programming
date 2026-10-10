#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

vector<int> zeroPrefix(vector<int>& a, int n) {
    vector<int> pg(n + 1, 0), ok(n + 1, 0);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (st.size() && a[st.back()] <= a[i]) st.pop_back();
        pg[i] = st.size() ? st.back() : 0;
        st.pb(i);
    }

    map<int, int> lastGood;
    ok[0] = 1;
    for (int r = 1; r <= n; r++) {
        if (lastGood.count(a[r]) && lastGood[a[r]] > pg[r]) ok[r] = 1;
        if (ok[r - 1]) lastGood[a[r]] = r;
    }
    return ok;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> pre = zeroPrefix(a, n);
    vector<int> rev(n + 1);
    for (int i = 1; i <= n; i++) rev[i] = a[n + 1 - i];
    vector<int> revOk = zeroPrefix(rev, n);
    vector<int> suf(n + 2, 0);
    for (int i = 1; i <= n + 1; i++) suf[i] = revOk[n + 1 - i];

    if (pre[n]) {
        cout << 0 << endl;
        return;
    }

    vector<int> pg(n + 1, 0), ng(n + 1, n + 1);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (st.size() && a[st.back()] <= a[i]) st.pop_back();
        pg[i] = st.size() ? st.back() : 0;
        st.pb(i);
    }
    st.clear();
    for (int i = n; i >= 1; i--) {
        while (st.size() && a[st.back()] <= a[i]) st.pop_back();
        ng[i] = st.size() ? st.back() : n + 1;
        st.pb(i);
    }

    vector<int> lastPre(n + 1, -1), firstSuf(n + 3, n + 2);
    for (int i = 0; i <= n; i++) lastPre[i] = pre[i] ? i : (i ? lastPre[i - 1] : -1);
    for (int i = n + 1; i >= 1; i--) firstSuf[i] = suf[i] ? i : firstSuf[i + 1];

    for (int r = 2; r <= n; r++) {
        if (!suf[r + 1]) continue;
        int L = max(pg[r], 1);
        int j = lastPre[r - 2];
        if (j >= L - 1) {
            cout << 1 << endl << j + 1 << " " << a[r] << endl;
            return;
        }
    }

    for (int l = 1; l < n; l++) {
        if (!pre[l - 1]) continue;
        int R = min(ng[l], n);
        int j = firstSuf[l + 2];
        if (j <= R + 1) {
            cout << 1 << endl << j - 1 << " " << a[l] << endl;
            return;
        }
    }

    int LOG = 1;
    while ((1 << LOG) <= n) LOG++;
    vector<vector<int>> sp(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) sp[0][i] = a[i];
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            sp[k][i] = max(sp[k - 1][i], sp[k - 1][i + (1 << (k - 1))]);
        }
    }
    auto rangeMax = [&](int L, int R) {
        int k = __lg(R - L + 1);
        return max(sp[k][L], sp[k][R - (1 << k) + 1]);
    };

    map<int, vector<int>> goodL;
    for (int l = 1; l <= n; l++) {
        if (pre[l - 1]) goodL[a[l]].pb(l);
    }

    for (int r = 3; r <= n; r++) {
        int p = pg[r];
        if (p <= 1 || !suf[r + 1] || !goodL.count(a[r])) continue;

        int L = 1, R = p - 1, q = 0;
        while (L <= R) {
            int M = (L + R) / 2;
            if (rangeMax(M, p - 1) > a[r]) {
                q = M;
                L = M + 1;
            } else {
                R = M - 1;
            }
        }

        vector<int>& pos = goodL[a[r]];
        auto it = upper_bound(pos.begin(), pos.end(), q);
        if (it != pos.end() && *it < p) {
            cout << 1 << endl << p << " " << a[r] << endl;
            return;
        }
    }

    cout << 2 << endl;
    cout << 1 << " " << 1000000000 << endl;
    cout << n << " " << 1000000000 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

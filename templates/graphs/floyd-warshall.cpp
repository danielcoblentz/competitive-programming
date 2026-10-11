#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m; // n = num nodes, m = num edges
    cin >> n >> m;

    //make the matrix & fill with inf init path weight unless equal then its zero
    vector<vector<ll>> dst(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dst[i][j] = 0;
            else dst[i][j] = INF;
        }
    }

    //add the edges for each pair and keep the cheaper one when we lsit hte same pair twice, the seond line sets the reverse direction because its undirected

    for (int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        dst[a][b] = min(dst[a][b], w);
        dst[b][a] = min(dst[b][a], w);
    }

    // find shortest distance
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dst[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (dst[k][j] == INF) continue;
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]) ;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (dst[i][j] == INF ? -1 : dst[i][j]) << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

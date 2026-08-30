#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    //  edge case - need at least 2 elements in a for every element in b
    if (n < 2 * m) {
        cout << "NO\n";
        return;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // check each b[i] is between its matching bounds in arr a
    for (int i = 0; i < m; i++) {
        if (b[i] <= a[i] || b[i] >= a[n - m + i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}


/*
input:
11
2 1
1 3
2
3 2
1 3 5
2 4
4 2
1 3 5 7
4 6
4 2
2 5 8 11
1 10
4 2
1 4 7 9
3 10
5 2
10 1 100 6 4
90 5
6 3
1 4 10 20 30 40
3 15 35
4 2
1 2 3 100
4 5
7 3
1 8 3 30 18 12 25
2 15 28
4 1
1 2 3 5
4
4 2
1 3 5 6
2 4


output:
YES
NO
YES
NO
NO
YES
YES
NO
YES
YES
YES

*/
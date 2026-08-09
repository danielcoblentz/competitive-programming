#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int N = 2 * n;
    ll red = 0, blue = 0;

    // s[i] is i + 1, so an even (blue) sits at odd i
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            if (i % 2 == 1) red++;
            else blue++;
        }
    }

    // every front moves once swapping which team it scores for
    for (int i = 0; i < N; i++) {
        if (s[i] == '1' && s[(i + 1) % N] == '0') {
            if (i % 2 == 1) {
                red--, blue++;
            } else {
                red++, blue--;
            }
        }
    }

    cout << red << " " << blue << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

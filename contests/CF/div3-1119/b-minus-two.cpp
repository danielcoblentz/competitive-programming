#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    // odds all collapse to 1 and stay there
    // evens land on the 0 <-> 2 cycle, and a % 4 determines which of the two they land on
    ll odd = 0, zero = 0, two = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a % 2) {
            odd++;
        } else if (a % 4 == 0) {
            zero++;
        } else {
            two++;
        }
    }

    cout << max(odd, max(zero, two)) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    // 2 = -1 mod 3, so the segment l..r is divisible by 3 exactly when the alternating
    // prefix sums q[l-1] and q[r] agree mod 3, where q[i] = q[i-1] + (-1)^i * s[i]
    // f is then the number of equal pairs among q[0..n], minimized when the n + 1
    // prefixes split as evenly as possible over the three residues
    if (n == 1) {
        cout << "1" << endl;
        return;
    }
    if (n == 2) {
        cout << "11" << endl;
        return;
    }

    // a one at position i moves q by +1 at even i and by -1 at odd i, so a block of length
    // b between two ones lands on a new residue only when b is even
    int N = n + 1, k = N / 3, r = N % 3;
    string s(n, '0');
    if (r == 0 && k % 2) {
        // k is odd so no even middle block works, three ones instead: the blocks
        // k - 2, k, 2, k step away, back to 0, then away again, so each residue gets k
        int i1 = k - 2, i2 = i1 + k, i3 = i2 + 2;
        s[i1 - 1] = s[i2 - 1] = s[i3 - 1] = '1';
    } else {
        // two ones cutting 0..n into blocks a, b, N - a - b with b even
        int a = k, b = k;
        if (r == 1) {
            if (k % 2) {
                b = k + 1;
            } else {
                a = k + 1;
            }
        } else if (r == 2) {
            a = k + 1;
            if (k % 2) b = k + 1;
        }
        s[a - 1] = s[a + b - 1] = '1';
    }

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

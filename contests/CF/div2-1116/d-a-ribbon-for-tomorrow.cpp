#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;
const int MAXN = 2000005;

// reversing s[l..r] with s[l] == s[r] leaves those two cells alone, so on the
// transition array t[i] = (s[i] != s[i+1]) the move is "reverse a substring with an
// even number of 1s", writing t as gaps of 0s around its 1s, every legal reversal
// moves a gap by an even number of positions, so a gap keeps the parity of its index,
// and the gaps are the maximal blocks of s minus one, so the answer is stars and bars
// over the even-indexed blocks and the odd-indexed blocks, independently

ll fact[MAXN], invFact[MAXN];

ll modPow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void buildFact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[MAXN - 1] = modPow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i > 0; i--) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }
}

ll binom(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// ways to spread `zeros` identical 0s over `slots` gaps
ll spread(ll zeros, ll slots) {
    // empty product, only valid when there is nothing left to place
    if (slots == 0) {
        return zeros == 0 ? 1 : 0;
    }
    return binom((int)(zeros + slots - 1), (int)(slots - 1));
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // walk the maximal blocks; block i contributes (length - 1) zeros to gap i,
    // and only the parity of i matters
    ll sumE = 0, sumO = 0;
    ll cntE = 0, cntO = 0;

    int block = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        ll gap = (j - i) - 1;

        if (block % 2 == 0) {
            sumE += gap;
            cntE++;
        } else {
            sumO += gap;
            cntO++;
        }

        block++;
        i = j;
    }

    cout << spread(sumE, cntE) * spread(sumO, cntO) % MOD << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    buildFact();

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

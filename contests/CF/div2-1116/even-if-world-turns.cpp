#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll extendedGcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll modInverse(ll a, ll mod) {
    ll x, y;
    extendedGcd((a % mod + mod) % mod, mod, x, y);
    return (x % mod + mod) % mod;
}

// get count and sums the black cells and sums their 0-indexed rows and cols, mod n
void scanPicture(vector<string>& grid, int N, ll& w, ll& sumR, ll& sumC) {
    w = 0, sumR = 0, sumC = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == '#') {
                w++;
                sumR += r;
                sumC += c;
            }
        }
    }
    sumR %= N;
    sumC %= N;
}

void chtholly() {
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int r = 0; r < N; r++) {
        cin >> grid[r];
    }

    int xr, xc;
    cin >> xr >> xc;
    xr--, xc--;

    ll w, sumR, sumC;
    scanPicture(grid, N, w, sumR, sumC);

    // the sums we need so the centroid lands on the target
    ll wantR = (w % N) * (ll)xr % N;
    ll wantC = (w % N) * (ll)xc % N;

    int dr = (int)(((wantR - sumR) % N + N) % N);
    int dc = (int)(((wantC - sumC) % N + N) % N);

    // if already correct, so swap a cell with itself and leave the picture alone
    if (dr == 0 && dc == 0) {
        cout << "1 1 1 1\n";
        return;
    }

    // move one black cell by (dr, dc) onto a white cell
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] != '#') {
                continue;
            }
            int newR = (r + dr) % N, newC = (c + dc) % N;
            if (grid[newR][newC] == '.') {
                cout << r + 1 << " " << c + 1 << " " << newR + 1 << " " << newC + 1 << "\n";
                return;
            }
        }
    }
}

void willem() {
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int r = 0; r < N; r++) {
        cin >> grid[r];
    }

    ll w, sumR, sumC;
    scanPicture(grid, N, w, sumR, sumC);

    // the picture may have been inverted center does not care abt it
    ll inv = modInverse(w % N, N);
    cout << sumR * inv % N + 1 << " " << sumC * inv % N + 1 << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string run;
    cin >> run;

    int t;
    cin >> t;
    while (t--) {
        if (run == "first") {
            chtholly();
        } else {
            willem();
        }
    }
    return 0;
}

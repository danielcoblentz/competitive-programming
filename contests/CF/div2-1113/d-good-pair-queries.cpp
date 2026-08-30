

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    string s, t;
    cin >> s >> t;
    vector<int> prefix_00(n + 1, 0), prefix_11(n + 1, 0);
    vector<int> prefix_01(n + 1, 0), prefix_10(n + 1, 0);

    /*
    there are 4 situations we an have for each pairing: 
        1: both strings have 0 at index i
        2: both strings have 1 at index i
        3: string s has 0 and string t has 1
        4: vice versa case for 3
    */

    //count of matching character pairs from idx 0 up to idx i−1
    for (int i = 0; i < n; i++) {
        prefix_00[i + 1] = prefix_00[i] + (s[i] == '0' && t[i] == '0');
        prefix_11[i + 1] = prefix_11[i] + (s[i] == '1' && t[i] == '1');
        prefix_01[i + 1] = prefix_01[i] + (s[i] == '0' && t[i] == '1');
        prefix_10[i + 1] = prefix_10[i] + (s[i] == '1' && t[i] == '0');
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        //ans queries from spef ranges l, r 
        int c00 = prefix_00[r] - prefix_00[l - 1];
        int c11 = prefix_11[r] - prefix_11[l - 1];
        int c01 = prefix_01[r] - prefix_01[l - 1];
        int c10 = prefix_10[r] - prefix_10[l - 1];

//get total matches and the excess mismatches -- cannot delete maimatches bc no single character can be a mode in both strings simultaneously
        if (c00 + c11 >= abs(c01 - c10)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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
3
2 2
01
10
1 1
1 2
5 1
11111
11111
1 3
5 1
00011
01111
1 5


NO
YES
YES
YES


*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    int n;
    cin >> n;

    vector<int> a(2 * n + 1), first(n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];

    vector<ll> dp(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++){
        dp[i] = dp[i-1] + 1;                // take a[i] alone: scores 1
        int firstPos = first[a[i]];         // where a[i] appeared before, 0 if never

        if (firstPos){
            ll len = i - firstPos + 1;      // delete the whole block [firstPos, i]
            dp[i] = max(dp[i], dp[firstPos - 1] + len * len);
        }
        else{
            first[a[i]] = i;
        }
    }
    cout << dp[2 * n] << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}



/*
sample input:
6
1
1 1
2
1 2 1 2
2
1 2 2 1
3
1 1 2 3 3 2
3
1 2 3 3 2 1
4
1 2 3 4 1 2 3 4


otuput:
4
10
16
20
36
28

*/

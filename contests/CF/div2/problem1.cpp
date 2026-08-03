#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    s.erase(s.find('0'), 1);
    s.erase(s.find('1'), 1);
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
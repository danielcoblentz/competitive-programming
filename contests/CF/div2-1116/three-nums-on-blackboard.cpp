#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> nums = {a, b, c};
    sort(nums.begin(), nums.end());

    // shrink the largest down to the sum of the other two until it fits
    while (nums[2] > nums[0] + nums[1]) {
        nums[2] = nums[0] + nums[1];
        sort(nums.begin(), nums.end());
    }

    cout << (nums[2] - nums[0]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

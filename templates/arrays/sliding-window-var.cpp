#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::min;

int shortestSubarray(vector<int>& nums, int target) {
    int L = 0, total = 0;
    int length = INT_MAX;

    for (int R = 0; R < nums.size(); R++) {
        total += nums[R];
        while (total >= target) {
            length = min(R - L + 1, length);
            total -= nums[L];
            L++;
        }
    }
    if (length == INT_MAX) {
        return 0;
    }
    return length;
}

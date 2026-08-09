#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

bool closeDuplicates(vector<int>& nums, int k) {
    unordered_set<int> window; // Cur window of size <= k
    int L = 0;

    for (int R = 0; R < nums.size(); R++) {
        if (R - L + 1 > k) {
            window.erase(nums[L]);
            L++;
        }
        if (window.count(nums[R]) > 0) {
            return true;
        }
        window.insert(nums[R]);
    }
    return false;
}

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

void helper(int i, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& subsets) {
    if (i >= nums.size()) {
        subsets.push_back(vector<int>(curSet));
        return;
    }
    // decision to include nums[i]
    curSet.push_back(nums[i]);
    helper(i + 1, nums, curSet, subsets);
    curSet.pop_back();

    // decision NOT to include nums[i]
    helper(i + 1, nums, curSet, subsets);
}

vector<vector<int>> subsetsWithoutDuplicates(vector<int>& nums) {
    vector<int> curSet;
    vector<vector<int>> subsets;
    helper(0, nums, curSet, subsets);
    return subsets;
}


void helper2(int i, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& subsets) {
    if (i >= nums.size()) {
        subsets.push_back(vector<int>(curSet));
        return;
    }

    // decision to include nums[i]
    curSet.push_back(nums[i]);
    helper2(i + 1, nums, curSet, subsets);
    curSet.pop_back();

    // decision NOT to include nums[i]
    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
    }
    helper2(i + 1, nums, curSet, subsets);
}

vector<vector<int>> subsetsWithDuplicates(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> curSet;
    vector<vector<int>> subsets;
    helper2(0, nums, curSet, subsets);
    return subsets;
}

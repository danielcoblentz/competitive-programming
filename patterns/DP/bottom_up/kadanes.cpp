#include <vector>
#include <algorithm>

using std::vector;
using std::max;

// Kadane's Algorithm — Maximum Subarray Sum
// Given an array of integers, return the largest sum obtainable
// from any contiguous (non-empty) subarray.
//
// Idea: scan left to right keeping curSum, the best subarray sum
// ending at the current element. Before extending, drop curSum if
// it has gone negative (a negative prefix can only hurt), then add
// the current element. maxSum tracks the best seen so far.
//
// Time: O(n), Space: O(1)
// Where n is the number of elements.
int kadanes(vector<int>& nums) {
    int maxSum = nums[0];
    int curSum = 0;

    for (int n : nums) {
        curSum = max(curSum, 0);
        curSum += n;
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

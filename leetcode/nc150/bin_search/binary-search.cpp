class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int k = 0;
        for (int b = n / 2; b >= 1; b /= 2) {
            while (k + b < n && nums[k + b] <= target) k += b;
        }
        if (nums[k] == target) return k;
        return -1;
    }
};


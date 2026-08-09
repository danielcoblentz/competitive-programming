#include <bits/stdc++.h>
using namespace std;

// where to put a recursive helper in c++, using subsets as the example
// c++ has no nested named functions, this does not compile:
//
//     vector<vector<int>> subsets(vector<int>& nums) {
//         void dfs(int i) { ... }   // error: a function-definition is not allowed here
//     }


// 1) free helper at file scope, what templates/backtracking/subsets.cpp does, and the
// right choice when you own main(), index first, inputs next, mutable state last
void helper(int i, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& res) {
    if (i >= nums.size()) {
        res.push_back(curSet);
        return;
    }

    // decision to include nums[i]
    curSet.push_back(nums[i]);
    helper(i + 1, nums, curSet, res);
    curSet.pop_back();

    // decision not to include nums[i]
    helper(i + 1, nums, curSet, res);
}

vector<vector<int>> subsetsFree(vector<int>& nums) {
    vector<int> curSet;
    vector<vector<int>> res;
    helper(0, nums, curSet, res);
    return res;
}


// 2) private member, the leetcode shape: the judge calls subsets() with a fixed
// signature, so the recursion lives next to it, the shared state moves into fields,
// which is why dfs only needs the index
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // reset, the judge may reuse the same object for the next test case
        nums_ = nums;
        curSet_.clear();
        res_.clear();
        dfs(0);
        return res_;
    }

private:
    vector<int> nums_;
    vector<int> curSet_;
    vector<vector<int>> res_;

    void dfs(int i) {
        if (i >= nums_.size()) {
            res_.push_back(curSet_);
            return;
        }
        curSet_.push_back(nums_[i]);
        dfs(i + 1);
        curSet_.pop_back();
        dfs(i + 1);
    }
};


// 3) lambda, the closest thing to a nested function, [&] captures nums/curSet/res so
// they are not parameters, but a lambda cannot call itself by name, so it takes itself
// as `self`, zero overhead unlike wrapping it in std::function
vector<vector<int>> subsetsLambda(vector<int>& nums) {
    vector<int> curSet;
    vector<vector<int>> res;

    auto dfs = [&](auto&& self, int i) -> void {
        if (i >= nums.size()) {
            res.push_back(curSet);
            return;
        }
        curSet.push_back(nums[i]);
        self(self, i + 1);
        curSet.pop_back();
        self(self, i + 1);
    };
    dfs(dfs, 0);

    return res;
}


// the std::function version reads better but type-erases every call, so it is slower,
// only reach for it if the self-parameter version bothers you
vector<vector<int>> subsetsStdFunction(vector<int>& nums) {
    vector<int> curSet;
    vector<vector<int>> res;

    function<void(int)> dfs = [&](int i) {
        if (i >= nums.size()) {
            res.push_back(curSet);
            return;
        }
        curSet.push_back(nums[i]);
        dfs(i + 1);
        curSet.pop_back();
        dfs(i + 1);
    };
    dfs(0);

    return res;
}


int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> a = subsetsFree(nums);
    vector<vector<int>> b = Solution().subsets(nums);
    vector<vector<int>> c = subsetsLambda(nums);
    vector<vector<int>> d = subsetsStdFunction(nums);

    cout << "all four agree: " << (a == b && b == c && c == d) << "\n";
    cout << a.size() << " subsets\n";
    for (vector<int> sub : a) {
        cout << "{";
        for (int i = 0; i < sub.size(); i++) {
            cout << (i ? "," : "") << sub[i];
        }
        cout << "}\n";
    }
    return 0;
}

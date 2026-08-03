class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        set<int>seen;
        int l = 0;

        for (int r = 0; r < s.size(); r++){
            while (seen.contains(s[r])){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            res = max(r - l + 1, res);
        }
        return res;
    }
};

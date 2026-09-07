class Solution {
public:
    int characterReplacement(string s, int k) {
        //edge case
        if (s.empty()) return 0;


        unordered_map<char, int> count;
        int res = 0;
        int l = 0, maxf = 0;

        for (int r = 0; r < s.size(); r++){
            //populate window & get max freq char at any point in time betene l, r 
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k){
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;

    }
};
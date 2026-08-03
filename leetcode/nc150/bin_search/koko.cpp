#include <algorithm>
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(begin(piles), end(piles)), ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long total_hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                total_hours += (piles[i] + (long long)mid - 1) / mid;
            }

            if (total_hours <= h) {
                ans = mid;       
                high = mid - 1;  
            } else {
                low = mid + 1;  
            }
        }
        return ans;
    }
};
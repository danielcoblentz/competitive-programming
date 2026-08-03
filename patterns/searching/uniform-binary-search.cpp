#include <bits/stdc++.h>
using namespace std;

// Jump-based binary search ("binary search by jumping").
// Alternative to lo/hi binary search: start at index 0 and make jumps whose
// length halves each round (n/2, n/4, ..., 1). On each round, keep advancing
// while the next jump would land on a value still <= x. When the jumps shrink
// past 1, k is the largest index with array[k] <= x.
// Requires: array sorted in ascending order. Runs in O(log n).
// Returns the index of x, or -1 if not present.
int search(const vector<int>& array, int x) {
    int n = array.size();
    if (n == 0) return -1;

    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k + b < n && array[k + b] <= x) k += b;
    }
    // k is now the largest index with array[k] <= x
    if (array[k] == x) return k;   // x found at index k
    return -1;                     // x not present
}

int main() {
    vector<int> array = {1, 3, 4, 7, 9, 11, 15};
    int x = 9;

    int idx = search(array, x);
    if (idx != -1) cout << x << " found at index " << idx << "\n";
    else cout << x << " not found\n";

    return 0;
}

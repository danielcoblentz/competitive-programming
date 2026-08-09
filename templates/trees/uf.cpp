#include <unordered_map>

using std::unordered_map;

class UnionFind {
public:
    unordered_map<int, int> par_;
    unordered_map<int, int> rank_;

    UnionFind(int n) {
        for (int i = 1; i <= n; i++) {
            par_[i] = i;
            rank_[i] = 0;
        }
    }

    int find(int x) {
        // Finds the root of x
        if (x != par_[x]) {
            par_[x] = find(par_[x]);
        }
        return par_[x];
    }

    // `union` is a reserved keyword in C++, so the method has to be named
    // something else. Return false if already connected, true otherwise.
    bool unionSets(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }

        if (rank_[p1] > rank_[p2]) {
            par_[p2] = p1;
        } else if (rank_[p1] < rank_[p2]) {
            par_[p1] = p2;
        } else {
            par_[p1] = p2;
            rank_[p2] += 1;
        }
        return true;
    }
};

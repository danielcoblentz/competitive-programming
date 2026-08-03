#include <iostream>
#include <vector>
#include <functional>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Map each course to its prerequisites.
        // Keys are exactly 0..numCourses-1, so a vector replaces the dict comprehension.
        vector<vector<int>> preMap(numCourses);
        for (auto& p : prerequisites) {
            int crs = p[0], pre = p[1];
            preMap[crs].push_back(pre);
        }

        // Store all courses along the current DFS path
        vector<bool> visiting(numCourses, false);

        std::function<bool(int)> dfs = [&](int crs) -> bool {
            if (visiting[crs]) {
                // Cycle detected
                return false;
            }
            if (preMap[crs].empty()) return true;

            visiting[crs] = true;
            for (int pre : preMap[crs]) {
                if (!dfs(pre)) return false;
            }
            visiting[crs] = false;
            preMap[crs].clear();  // crs is known-good, never walk it again
            return true;
        };

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    vector<vector<int>> acyclic = {{0, 1}};
    cout << (s.canFinish(2, acyclic) ? "true" : "false") << endl;  // true

    vector<vector<int>> cyclic = {{0, 1}, {1, 0}};
    cout << (s.canFinish(2, cyclic) ? "true" : "false") << endl;  // false

    // Disconnected: cycle hides in a component no single root reaches
    vector<vector<int>> split = {{0, 1}, {2, 3}, {3, 2}};
    cout << (s.canFinish(4, split) ? "true" : "false") << endl;  // false

    return 0;
}

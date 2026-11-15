#include <vector>
#include <queue>

using std::vector;
using std::queue;

vector<int> topoSort(vector<vector<int>>& edges, int n) {
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (const vector<int>& edge : edges) {
        int n1 = edge[0], n2 = edge[1];
        adj[n1].push_back(n2);
        indegree[n2]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> res;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        for (int nei : adj[cur]) {
            indegree[nei]--;
            if (indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    if ((int)res.size() < n) {
        return vector<int>();
    }
    return res;
}

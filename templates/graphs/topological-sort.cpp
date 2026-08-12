#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

const int UNVISITED = 0, VISITING = 1, VISITED = 2;

// VISITING means the node is still on the recursion stack, so seeing it again is a back edge,
// that is the cycle, VISITED means fully explored and safe to skip
bool dfs(int node, vector<vector<int>>& adj, vector<int>& states, vector<int>& res) {
    if (states[node] == VISITING) return false;
    if (states[node] == VISITED) return true;

    states[node] = VISITING;
    for (int nei : adj[node]) {
        if (!dfs(nei, adj, states, res)) {
            return false;
        }
    }

    // post order, a node is appended only after everything it points to is done
    states[node] = VISITED;
    res.push_back(node);
    return true;
}

// edges are {src, dst} meaning src comes before dst, nodes are 0 to n - 1
// an empty result means the graph has a cycle and no order exists
vector<int> topologicalSort(vector<vector<int>>& edges, int n) {
    vector<vector<int>> adj(n);
    for (vector<int> edge : edges) {
        int s = edge[0], d = edge[1];
        adj[s].push_back(d);
    }

    vector<int> states(n, UNVISITED);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (!dfs(i, adj, states, res)) {
            return vector<int>();
        }
    }

    // post order puts dependencies first, so flip it
    reverse(res.begin(), res.end());
    return res;
}

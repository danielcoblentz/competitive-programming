// Floyd-Warshall: shortest path between EVERY pair of nodes.
// O(n^3) time, O(n^2) memory, so it's the right pick when n is small (~500 or
// less) and you need all pairs. Works with negative edge weights.
// If the graph is sparse, n runs of Dijkstra is O(n*m*log n) and beats this.
//
// input: n m, then m lines of "a b w" (edge a<->b with weight w)

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::min;

const int N = 505;              // max nodes + 1, since we're 1-indexed
const long long INF = 1e18;     // "no path". long long matters: with n=500 and
                                // weights up to 1e9 a real path hits ~5e11, which
                                // blows past int

int n, m;
long long dist[N][N];           // dist[i][j] = best distance found so far

int main(){
    std::ios::sync_with_stdio(false);   // the output is n^2 numbers, so untying
    cin.tie(nullptr);                   // cin/cout from stdio is worth it

    cin >> n >> m;

    // 0 to yourself, INF to everyone else until we see an edge
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j ? 0 : INF);
        }
    }

    // read edges straight into dist. min() handles the input listing a pair
    // twice, and unlike a separate adj matrix a 0-weight edge still registers
    for (int e = 0; e < m; e++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);   // drop for a directed graph
    }

    // k = the highest numbered node a path is allowed to pass through, so it
    // MUST be the outer loop. by the time we read dist[i][k], every route that
    // only goes through 1..k-1 is already final
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            long long dik = dist[i][k];
            if (dik >= INF / 2) continue;   // i can't reach k, so k helps nothing
            for (int j = 1; j <= n; j++) {
                // either avoid k, or go i -> k -> j
                dist[i][j] = min(dist[i][j], dik + dist[k][j]);
            }
        }
    }

    // getting back to yourself for a negative cost means a negative cycle, and
    // every distance touching it is meaningless
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            cout << "negative cycle\n";
            return 0;
        }
    }

    // compare against INF/2, not INF: adding a negative weight to INF leaves a
    // value that's still nonsense but no longer exactly INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (dist[i][j] >= INF / 2 ? -1 : dist[i][j]);
            cout << (j == n ? '\n' : ' ');
        }
    }
    return 0;
}

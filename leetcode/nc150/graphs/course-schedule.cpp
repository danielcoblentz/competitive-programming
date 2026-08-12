#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define vvi vector<vector<int>>
#define vi vector<int>

const int UNVISITED = 0, VISITING = 1, VISITED = 2;

class Solution{
    public:
    bool canFinish(int numCourses, vvi& crs){
        unordered_map<int, vi>adj;
        int n = numCourses;

        for(vi& p: crs){
            adj[p[0]].pb(p[1]);
        }
        vi states(n, UNVISITED);


        for (int i = 0; i < n; i++){
            if (!dfs(i, states, adj)) return false;
        }
        return true;

    }

    bool dfs(int node, vi& states, unordered_map<int, vi>& adj){
        if (states[node] == VISITING) return false;
        if (states[node] == VISITED) return true;

        states[node] = VISITING;
        for (auto& nei: adj[node]){
            if (!dfs(nei, states, adj)) return false;

        }
        states[node] = VISITED;
        return true;

    }
};

int main(){
    Solution s;
    vvi crs = {{0,1}, {1,0}};
    auto ans = s.canFinish(2, crs);

    cout << ans << "\n";
}

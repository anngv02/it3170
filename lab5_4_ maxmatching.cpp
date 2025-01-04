#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001; // Maximum number of tasks or staffs
vector<int> adj[MAXN];  // Adjacency list for the bipartite graph
vector<bool> visited;   // Visited array for DFS
vector<int> match;      // Matching array

// DFS to find an augmenting path
bool dfs(int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            // If v is not matched or we can find an augmenting path
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maximumBipartiteMatching(int n, int m) {
    match.assign(m + 1, -1); // Initialize all staffs as unmatched
    int maxMatch = 0;

    for (int i = 1; i <= n; i++) {
        visited.assign(m + 1, false); // Reset visited for each task
        if (dfs(i)) {
            maxMatch++;
        }
    }
    return maxMatch;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int staff;
            cin >> staff;
            adj[i].push_back(staff); // Task i can be performed by staff
        }
    }

    cout << maximumBipartiteMatching(n, m) << endl;
    return 0;
}


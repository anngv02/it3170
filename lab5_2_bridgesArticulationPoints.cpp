#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, vector<int> adj[], vector<bool> &visited, 
         vector<int> &disc, vector<int> &low, vector<bool> &isArticulation, 
         vector<pair<int, int>> &bridges, int &time) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            dfs(v, u, adj, visited, disc, low, isArticulation, bridges, time);

            // Update low value of u
            low[u] = min(low[u], low[v]);

            // Check for articulation point
            if (parent != -1 && low[v] >= disc[u]) {
                isArticulation[u] = true;
            }

            // Check for bridge
            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parent) {
            // Update low value of u for back edge
            low[u] = min(low[u], disc[v]);
        }
    }

    // Special case for root
    if (parent == -1 && children > 1) {
        isArticulation[u] = true;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> adj[N + 1]; // Adjacency list for the graph

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    vector<bool> visited(N + 1, false);
    vector<int> disc(N + 1, -1);   // Discovery time of each vertex
    vector<int> low(N + 1, -1);    // Lowest discovery time reachable
    vector<bool> isArticulation(N + 1, false); // Articulation points
    vector<pair<int, int>> bridges; // Bridges
    int time = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, disc, low, isArticulation, bridges, time);
        }
    }

    int articulationCount = 0;
    for (int i = 1; i <= N; i++) {
        if (isArticulation[i]) {
            articulationCount++;
        }
    }

    cout << articulationCount << " " << bridges.size() << endl;
    return 0;
}


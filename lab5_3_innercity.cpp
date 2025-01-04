#include <bits/stdc++.h>
using namespace std;

struct State {
    int city, cost;
    bool operator>(const State &other) const {
        return cost > other.cost;
    }
};

int n, m;
vector<int> C(5001), D(5001);
vector<vector<int>> adj(5001);
int dist[5001];

void dijkstra() {
    priority_queue<State, vector<State>, greater<State>> pq;
    fill(dist, dist + n + 1, INT_MAX);
    dist[1] = 0;
    pq.push({1, 0});

    while (!pq.empty()) {
        State curr = pq.top(); pq.pop();
        int u = curr.city, curCost = curr.cost;

        if (curCost > dist[u]) continue;

        queue<pair<int, int>> q;
        vector<int> visited(n + 1, 0);
        q.push({u, 0});
        visited[u] = 1;

        while (!q.empty()) {
            int city = q.front().first;
            int depth = q.front().second;
            q.pop();

            if (depth < D[u]) {
                for (int v : adj[city]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        q.push({v, depth + 1});
                        int newCost = curCost + C[u];
                        if (newCost < dist[v]) {
                            dist[v] = newCost;
                            pq.push({v, newCost});
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dijkstra();
    cout << (dist[n] == INT_MAX ? -1 : dist[n]) << endl;

    return 0;
}

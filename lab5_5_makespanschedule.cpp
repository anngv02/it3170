#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001; // S? task t?i ða
vector<int> adj[MAXN];   // Danh sách k?
vector<int> inDegree(MAXN, 0); // B?c vào c?a m?i ð?nh
vector<int> duration(MAXN, 0); // Th?i gian hoàn thành m?i task
vector<int> earliest(MAXN, 0); // Th?i gian hoàn thành s?m nh?t

int findEarliestCompletionTime(int n, int m) {
    queue<int> q; // Hàng ð?i ð? s?p x?p topo

    // Ðýa các ð?nh có b?c vào b?ng 0 vào hàng ð?i
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            earliest[i] = duration[i]; // Th?i gian hoàn thành chính là th?i gian th?c hi?n task
        }
    }

    // X? l? các ð?nh theo th? t? topo
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Duy?t qua các task ph? thu?c vào task u
        for (int v : adj[u]) {
            inDegree[v]--; // Gi?m b?c vào c?a ð?nh k?
            earliest[v] = max(earliest[v], earliest[u] + duration[v]); // C?p nh?t th?i gian hoàn thành
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // T?m th?i gian hoàn thành s?m nh?t c?a d? án
    return *max_element(earliest.begin() + 1, earliest.begin() + n + 1);
}

int main() {
    int n, m; // S? task và s? ràng bu?c
    cin >> n >> m;

    // Nh?p th?i gian th?c hi?n t?ng task
    for (int i = 1; i <= n; i++) {
        cin >> duration[i];
    }

    // Nh?p các ràng bu?c
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Thêm c?nh t? task u ð?n task v
        inDegree[v]++;       // Tãng b?c vào c?a task v
    }

    // Tính th?i gian hoàn thành s?m nh?t c?a d? án
    cout << findEarliestCompletionTime(n, m) << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001; // S? task t?i �a
vector<int> adj[MAXN];   // Danh s�ch k?
vector<int> inDegree(MAXN, 0); // B?c v�o c?a m?i �?nh
vector<int> duration(MAXN, 0); // Th?i gian ho�n th�nh m?i task
vector<int> earliest(MAXN, 0); // Th?i gian ho�n th�nh s?m nh?t

int findEarliestCompletionTime(int n, int m) {
    queue<int> q; // H�ng �?i �? s?p x?p topo

    // ��a c�c �?nh c� b?c v�o b?ng 0 v�o h�ng �?i
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            earliest[i] = duration[i]; // Th?i gian ho�n th�nh ch�nh l� th?i gian th?c hi?n task
        }
    }

    // X? l? c�c �?nh theo th? t? topo
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Duy?t qua c�c task ph? thu?c v�o task u
        for (int v : adj[u]) {
            inDegree[v]--; // Gi?m b?c v�o c?a �?nh k?
            earliest[v] = max(earliest[v], earliest[u] + duration[v]); // C?p nh?t th?i gian ho�n th�nh
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // T?m th?i gian ho�n th�nh s?m nh?t c?a d? �n
    return *max_element(earliest.begin() + 1, earliest.begin() + n + 1);
}

int main() {
    int n, m; // S? task v� s? r�ng bu?c
    cin >> n >> m;

    // Nh?p th?i gian th?c hi?n t?ng task
    for (int i = 1; i <= n; i++) {
        cin >> duration[i];
    }

    // Nh?p c�c r�ng bu?c
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Th�m c?nh t? task u �?n task v
        inDegree[v]++;       // T�ng b?c v�o c?a task v
    }

    // T�nh th?i gian ho�n th�nh s?m nh?t c?a d? �n
    cout << findEarliestCompletionTime(n, m) << endl;

    return 0;
}


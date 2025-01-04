#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 25; 
int n, K;
int c[MAXN][MAXN]; 
int load = 0; 
int f = 0, f_best = INT_MAX; 
vector<bool> visited(MAXN, false); 
vector<int> X(MAXN); 

int Cmin = INT_MAX; 


void updateBest() {
    if (f + c[X[2 * n]][0] < f_best) {
        f_best = f + c[X[2 * n]][0]; 
    }
}

bool check(int v, int k) {
    if (visited[v]) return false;
    if (v > n) { 
        if (!visited[v - n]) return false;
    } else { 
        if (load + 1 > K) return false; 
    }
    return true;
}

void tryRoute(int k) {
    for (int v = 1; v <= 2 * n; v++) {
        if (check(v, k)) {
            X[k] = v;
            f += c[X[k - 1]][X[k]];
            visited[v] = true;
            if (v <= n) load++; 
            else load--; 

            if (k == 2 * n) {
                updateBest();
            } else {
                if (f + Cmin * (2 * n + 1 - k) < f_best) {
                    tryRoute(k + 1);
                }
            }

            visited[v] = false;
            f -= c[X[k - 1]][X[k]];
            if (v <= n) load--;
            else load++;
        }
    }
}

int main() {
    cin >> n >> K;

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j) Cmin = min(Cmin, c[i][j]); 
        }
    }

    X[0] = 0;
    tryRoute(1);
    cout << f_best << endl;

    return 0;
}


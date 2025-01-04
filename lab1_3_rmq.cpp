#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
const int LOG = 20; 

int n;
int a[MAXN];
int M[LOG][MAXN]; 


int RMQ(int i, int j) {
    int k = log2(j - i + 1);
    if (a[M[k][i]] <= a[M[k][j - (1 << k) + 1]]) {
        return a[M[k][i]];
    } else {
        return a[M[k][j - (1 << k) + 1]];
    }
}

int main() {
    // Nh?p n
    cin >> n;
    
    // Nh?p m?ng a
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    for (int i = 0; i < n; i++) {
        M[0][i] = i;
    }

    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            if (a[M[k - 1][i]] < a[M[k - 1][i + (1 << (k - 1))]]) {
                M[k][i] = M[k - 1][i];
            } else {
                M[k][i] = M[k - 1][i + (1 << (k - 1))];
            }
        }
    }

    // Nh?p s? lý?ng truy v?n m
    int m;
    cin >> m;

    int sum = 0;
    for (int i = 0; i < m; i++) {
        int L, R;
        cin >> L >> R;
        sum += RMQ(L, R);
    }

    // In k?t qu? t?ng
    cout << sum << endl;

    return 0;
}


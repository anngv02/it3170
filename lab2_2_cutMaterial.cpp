// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int height, width;
int n;
int h[11], w[11];
int x[11], y[11], shape[11];
int can_cut;

int overlap_2_rec(int top_r1, int top_c1, int btm_r1, int btm_c1,
                  int top_r2, int top_c2, int btm_r2, int btm_c2) {
    int top_r = max(top_r1, top_r2);
    int btm_r = min(btm_r1, btm_r2);
    int top_c = max(top_c1, top_c2);
    int btm_c = min(btm_c1, btm_c2);
    
    if (top_r > btm_r || top_c > btm_c) return 0;
    return 1;
}

int overlap(int k, int i, int j, int right_shape) {
    if (k == 0) return 0;
    
    int top_r1 = i, top_c1 = j, btm_r1, btm_c1;
    int top_r2, top_c2, btm_r2, btm_c2;

    if (right_shape) {
        btm_r1 = top_r1 + h[k] - 1;
        btm_c1 = top_c1 + w[k] - 1;
    } else {
        btm_r1 = top_r1 + w[k] - 1;
        btm_c1 = top_c1 + h[k] - 1;       
    }
    
    for (int rec = 0; rec <= k - 1; rec++) {
        top_r2 = x[rec]; top_c2 = y[rec];
    
        if (shape[rec]) {
            btm_r2 = top_r2 + h[rec] - 1;
            btm_c2 = top_c2 + w[rec] - 1;
        } else {
            btm_r2 = top_r2 + w[rec] - 1;
            btm_c2 = top_c2 + h[rec] - 1;      
        }    
        
        if (overlap_2_rec(top_r1, top_c1, btm_r1, btm_c1,
                          top_r2, top_c2, btm_r2, btm_c2)) {
            return 1;
        }
    }
    return 0;
}

// void printSol() {
//     for (int i = 0; i < n) 
// }   

void Try(int k) {
    int hk, wk;

    for (int right_shape = 0; right_shape <= 1; right_shape++) {
        if (!right_shape) {
            hk = w[k]; wk = h[k];
        } else {
            hk = h[k]; wk = w[k];
        }
        
        for (int i = 1; i <= height - hk + 1; i++) {
            for (int j = 1; j <= width - wk + 1; j++) {
                if (!overlap(k, i, j, right_shape)) {
                    
                    x[k] = i; y[k] = j;
                    shape[k] = right_shape; 
                    
                    if (k == n - 1) {
                        can_cut = 1;
                        return;
                    } else Try(k + 1);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    
    // x[0] = 1; y[0] = 1; shape[0] = 0;
    // x[1] = 2; y[1] = 4; shape[1] = 0;
    
    cin >> height >> width;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];    
    }
    // cout << overlap(2, 5, 5, 0);
    Try(0);
    cout << can_cut;
}


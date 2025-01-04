#include <iostream>
#include <vector>
using namespace std;

const int MAX_W = 100;
const int MAX_H = 100;

int W, H, n; // W: chi?u r?ng, H: chi?u cao, n: s? h?nh ch? nh?t
vector<int> w, h; // kích thý?c các h?nh ch? nh?t
bool mark[MAX_W][MAX_H]; // lý?i ð? ðánh d?u các ô ð? ðý?c s? d?ng
int x[MAX_W], y[MAX_H], o[MAX_W]; // v? trí và hý?ng c?a các h?nh ch? nh?t

bool check(int vo, int vx, int vy, int k) {
    int wk = w[k], hk = h[k];
    if (vo == 1) {
        wk = h[k];
        hk = w[k];
    }
    if (vx + wk > W || vy + hk > H) return false;

    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            if (mark[i][j]) return false;
        }
    }
    return true;
}

void doMark(int vo, int vx, int vy, int k, bool mark_value) {
    int wk = w[k], hk = h[k];
    if (vo == 1) {
        wk = h[k];
        hk = w[k];
    }

    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            mark[i][j] = mark_value;
        }
    }
}

void solution() {
    cout << "Solution found:\n";
    for (int i = 0; i < n; i++) {
        cout << "Rectangle " << i + 1 << ": x = " << x[i] << ", y = " << y[i]
            << ", orientation = " << o[i] << "\n";
    }
    exit(0); // K?t thúc chýõng tr?nh n?u t?m th?y l?i gi?i
}

void Try(int k) {
    for (int vo = 0; vo <= 1; vo++) {
        int wk = w[k], hk = h[k];
        if (vo == 1) {
            wk = h[k];
            hk = w[k];
        }
        for (int vx = 0; vx <= W - wk; vx++) {
            for (int vy = 0; vy <= H - hk; vy++) {
                if (check(vo, vx, vy, k)) {
                    x[k] = vx;
                    y[k] = vy;
                    o[k] = vo;
                    doMark(vo, vx, vy, k, true); // Ðánh d?u

                    if (k == n - 1) {
                        solution();
                    }
                    else {
                        Try(k + 1);
                    }

                    doMark(vo, vx, vy, k, false); // B? ðánh d?u
                }
            }
        }
    }
}

int main() {
    cin >> W >> H >> n;
    w.resize(n);
    h.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
    }

    // Kh?i t?o lý?i ðánh d?u là chýa s? d?ng
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            mark[i][j] = false;
        }
    }

    // B?t ð?u th? t? h?nh ch? nh?t ð?u tiên
    Try(0);

    cout << "No solution found." << endl;
    return 0;
}


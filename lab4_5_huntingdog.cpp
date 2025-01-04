#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long res, tmp_res[1001];
long long x, y, c;
int last_eq[1001];

struct Point {
    long long x;
    long long y;
    long long c;
};

vector<Point> points;

void get_input() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> c;
        Point p{x, y, c};
        points.push_back(p);
    }
}

bool compare_point(Point p1, Point p2) {
    return (p1.x <= p2.x);
}

bool compare_sec_element(Point p1, Point p2) {
    return (p1.y <= p2.y);
}

void sort_via_sec_element() {
    int start = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (points[i].x != points[i + 1].x) {
            last_eq[start++] = i;
        }
    }
    
    last_eq[start] = n - 1;
    sort(points.begin(), points.begin() + last_eq[0] + 1, compare_sec_element);
    
    for (int i = 1; i <= start; i++) {
        sort(points.begin() + last_eq[i - 1] + 1, points.begin() + last_eq[i] + 1, compare_sec_element);
    }
}

void solve() {
    sort(points.begin(), points.end(), compare_point);
    sort_via_sec_element();
    
    tmp_res[0] = points[0].c;
    res = tmp_res[0];
    
    for (int i = 1; i < n; i++) {
        long long prev_arg = 0, prev_max = 0;
        
        for (int j = i - 1; j != -1; j--) {
            if (points[j].y <= points[i].y) {
                
                if (tmp_res[j] > prev_max) {
                    prev_max = tmp_res[j];
                }
                
            }
        }
        
        if (!prev_max) tmp_res[i] = points[i].c;
        else tmp_res[i] = points[i].c + prev_max;
        
        if (tmp_res[i] > res) res = tmp_res[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    get_input();
    solve();
    
    // for (int i = 0; i < n; i++) {
    //     cout << '(' << points[i].x << ", " << points[i].y 
    //                 << ", " << points[i].c << "); ";        
    // }
    // cout << '\n';
    
    cout << res << "\n";
    // while (1) {
    //     cout << '(' << points[arg_max].x << ", " << points[arg_max].y 
    //                 << ", " << points[arg_max].c << "); ";
    //     arg_max = prev_args[arg_max];
    //     if (arg_max == -1) break;
        
    // }
    return 0;
}


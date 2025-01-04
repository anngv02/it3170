#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(n);
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        // Remove indices outside the current window [i - l2, i - l1]
        while (!dq.empty() && dq.front() < i - l2) {
            dq.pop_front();
        }

        // Add potentially useful indices to the deque.
        // We only keep indices j such that dp[j] is maximal for all j in the current window.
        while (!dq.empty() && dp[dq.back()] <= dp[i - l1]) {
            dq.pop_back();
        }

        if (i >= l1) dq.push_back(i - l1);

        // Calculate dp[i] using the maximum dp value in the current window.
        if (!dq.empty()) {
            dp[i] = a[i] + dp[dq.front()];
        } else if (i < l1) {
            dp[i] = a[i];
        } else{
            dp[i] = -1e18; //Handle edge case where there is no valid previous state
        }
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}


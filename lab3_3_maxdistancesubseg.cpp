//C++ 
#include <bits/stdc++.h> 

using namespace std;

// Function to check if a distance d is feasible
bool canPlaceCows(const vector<int>& positions, int n, int c, int d) {
    int count = 1; // Place the first cow at the first position
    int last_position = positions[0];

    for (int i = 1; i < n; ++i) {
        if (positions[i] - last_position >= d) {
            ++count;
            last_position = positions[i];
            if (count == c) return true; // All cows placed
        }
    }

    return false;
}

int maximalMinimalDistance(vector<int>& positions, int n, int c) {
    sort(positions.begin(), positions.end()); // Sort positions

    int left = 1; // Minimal possible distance
    int right = positions[n - 1] - positions[0]; // Maximal possible distance
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(positions, n, c, mid)) {
            result = mid; // Update result with current valid distance
            left = mid + 1; // Try for a larger distance
        } else {
            right = mid - 1; // Try for a smaller distance
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, C;
        cin >> N >> C;

        vector<int> positions(N);
        for (int i = 0; i < N; ++i) {
            cin >> positions[i];
        }

        cout << maximalMinimalDistance(positions, N, C) << endl;
    }

    return 0;
}


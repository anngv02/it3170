//C++ 
#include <bits/stdc++.h> 
using namespace std;


int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    heights.push_back(0); 
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        s.push(i);
    }
    
    return maxArea;
}

int main() {
    int n, m;

    cin >> n;
    cin >> m;
    vector<vector<int>> A(n, vector<int>(m));
    vector<int> heights(m, 0); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            heights[j] = (A[i][j] == 1) ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    cout << maxArea << endl;

    return 0;
}


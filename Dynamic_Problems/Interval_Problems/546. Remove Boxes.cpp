#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>> dp(105, vector<vector<int>>(105, vector<int>(105)));
        int n = boxes.size();
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int k = 0; k < n; k++) {
                    if (dp[i][j][k] != 0) break; 
                    dp[i][j][k] = max(dp[i][j][k], (j - 1 < i ? 0 : dp[i][j - 1][0]) + (k + 1) * (k + 1));
                    for (int t = i; t <= j - 1; t++) {
                        if (boxes[t] == boxes[j]) {
                            dp[i][j][k] = max(dp[i][j][k], (t + 1 > j - 1 ? 0 : dp[t + 1][j - 1][0]) + dp[i][t][k + 1]);
                        }
                    }
                }
            }
        }
        return dp[0][n - 1][0];
    }
};


class Solution {
private:
    int dp[100][100][100];
public:
    int removeBoxes(vector<int>& boxes) {
        return calPoints(boxes, 0, boxes.size() - 1, 0);
    }

    int calPoints(vector<int>& boxes, int i, int j, int k) {
        if (i > j) return 0;
        if (dp[i][j][k] != 0) return dp[i][j][k];
        while (i < j && boxes[j] == boxes[j - 1]) {
            j--;
            k++;
        }

        dp[i][j][k] = calPoints(boxes, i, j - 1, 0) + (k + 1) * (k + 1);
        for (int t = i; t < j; t++) {
            if (boxes[t] == boxes[j]) {
                dp[i][j][k] = max(dp[i][j][k], calPoints(boxes, i, t, k + 1) + calPoints(boxes, t + 1, j - 1, 0));
            }
        }
        return dp[i][j][k];
    }
};
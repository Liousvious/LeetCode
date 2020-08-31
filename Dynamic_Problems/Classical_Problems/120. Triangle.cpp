#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
        return dfs(triangle, 0, 0, dp);
    }

    int dfs(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        if (i == triangle.size()) return 0;
        if (dp[i][j] != 0) return dp[i][j];

        return dp[i][j] = min(dfs(triangle, i + 1, j, dp), dfs(triangle, i + 1, j + 1, dp)) + triangle[i][j];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        vector<vector<int>> dp(triangle.size() + 1, vector<int>(triangle.size() + 1, 0));

        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
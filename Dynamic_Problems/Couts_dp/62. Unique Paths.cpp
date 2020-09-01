#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < m; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};

class Solution {
public:
    vector<vector<int>> memo;
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(n, vector<int>(m, 0));
        memorableDfs(n - 1, m - 1);
        return memo[n - 1][m - 1];
    }

    int memorableDfs(int i, int j) {
        if (i == 0 || j == 0) {
            return memo[i][j] = 1;
        }

        if (memo[i][j] != 0) return memo[i][j];

        int res = memorableDfs(i - 1, j) + memorableDfs(i, j - 1);
        memo[i][j] = res;
        return res;
    }
};
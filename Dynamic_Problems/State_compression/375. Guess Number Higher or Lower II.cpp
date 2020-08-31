#include <bits/stdc++.h>

using namespace std;

/**
%% assume that dp[i][j] denotes the minimal costs for guess the correct number in the internal [i,j] ,dp[i][j] = 0 when i = j

%% dp[i][j] = min(dp[i][j], max(dp[i][x - 1] + dp[x + 1][j]) + x)


**/


class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j) dp[i][j] = 0;
                else {
                    dp[i][j] = INT_MAX;
                    for (int x = i; x <= j; x++) {
                        dp[i][j] = min(dp[i][j], max(dp[i][x - 1], dp[x + 1][j]) + x);
                    }
                }
            }
        }
        return dp[1][n];
    }
};
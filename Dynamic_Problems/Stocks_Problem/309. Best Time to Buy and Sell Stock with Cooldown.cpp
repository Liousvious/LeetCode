#include <bits/stdc++.h>

using namespace std;

/*
define dp[i][j] the profit of the ith day under state j ,where j = 0, 1, 2 represents pocess, not pocess and freezen period.
dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i])
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
dp[i][2] = dp[i - 1][1]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3, INT_MIN));

        // Initialization
        dp[0][0] = - prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = dp[i - 1][1];
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};
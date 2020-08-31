#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4, INT_MIN));

        dp[0][0] = - prices[0];
        dp[0][1] = 0;
        dp[0][2] = - prices[0];
        dp[0][3] = 0;

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][3]);
    }
};
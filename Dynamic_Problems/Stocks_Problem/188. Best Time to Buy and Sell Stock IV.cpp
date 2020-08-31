#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k < 1) return 0;
        if (k >= prices.size() / 2) return greedy(prices);
        vector<vector<vector<int>>> dp(prices.size() ,vector<vector<int>>(k, vector<int>(2)));

        for (int i = 0; i < k; i++)
            dp[0][i][0] = - prices[0]; 
            
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0][0] = max(dp[i - 1][0][0], -prices[i]);
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] + prices[i]);
            for (int j = 1; j < k; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i]);
            }
        }
        return dp[prices.size() - 1][k - 1][1];
    }

    int greedy(vector<int> prices) {
        int max = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) max += prices[i] - prices[i - 1];
        }
        return max;
    }
};
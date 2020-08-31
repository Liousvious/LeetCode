#include <bits/stdc++.h>

using namespace std;

// INCOMPLETE PACKAGE PROBLEM

class Solution {
public:
    vector<int> memo;
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return -1;
        memo = vector<int>(amount, -1);
        return dfs(coins, amount);
    }

    int dfs(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;

        if (memo[amount - 1] != -1) return memo[amount - 1];

        int min = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int res = dfs(coins, amount - coins[i]);
            if (res >= 0 && res < min) min = res + 1;
        }

        memo[amount - 1] = (min == INT_MAX ? -1 : min);
        return memo[amount - 1];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return -1;

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, amount + 1));
        for (int i = 1; i <= coins.size(); i++) {
            dp[i][0] = 0;
        }

        int minSum = INT_MAX;
        for (int i = 1; i <= coins.size(); i++) {
            //int min = INT_MAX;
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i - 1] < 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
        return dp[coins.size()][amount] == amount + 1 ? -1 : dp[coins.size()][amount];
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i - 1])
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1); 
            }
        }
        return dp[amount] == amount + 1 ? -1: dp[amount];
    }
};
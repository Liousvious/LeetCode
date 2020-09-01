#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> memo;
    int change(int amount, vector<int>& coins) {
        if (coins.empty()) return 0;
        memo = vector<int>(amount, -1);
        return dfs(coins, amount);
    }

    int dfs(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;

        if (memo[amount - 1] != -1) return memo[amount - 1];
        int sum = 0;
        for (int i = 0; i < coins.size(); i++) {
            int res = dfs(coins, amount - coins[i]);
            if (res >= 0) sum += 1;
        }
        memo[amount - 1] = (sum == 0 ? -1 : sum);
        return memo[amount - 1];
    }
};


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        if (len == 0) {
            if (amount == 0) return 1;
            return 0;
        }
        vector<int> dp(amount + 1, 0);  
        dp[0] = 1;
        for (int i = coins[0]; i <= amount; i += coins[0]) {
            dp[i] = 1;
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
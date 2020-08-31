#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> coins(nums.size() + 2);
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2));
        for (int i = 1; i <= nums.size(); i++) {
            coins[i] = nums[i - 1];
        }
        coins[nums.size() + 1] = 1;
        coins[0] = 1;
        for (int i = nums.size(); i >= 0; i--) {
            for (int j = i + 1; j < nums.size() + 2; j++ ) {
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + \
                                 coins[i] * coins[k] * coins[j]);
                }
            }
        }
        return dp[0][nums.size() + 1];
    }
};



class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> coins(nums.size() + 2);
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));
        coins[0] = coins[nums.size() + 1] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            coins[i] = nums[i - 1];
        }
        return calCoins(coins, dp, 0, nums.size() + 1);    
    }

    int calCoins(vector<int>& coins, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];
        for (int k = i + 1; k < j; k++) {
            dp[i][j] = max(dp[i][j], calCoins(coins, dp, i, k) + calCoins(coins, dp, k, j) + \
                         coins[i] * coins[k] * coins[j]);
        }
        return dp[i][j];
    }
};
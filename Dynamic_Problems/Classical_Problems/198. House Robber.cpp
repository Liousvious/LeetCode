#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() < 2) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int maxCash = max(dp[0], dp[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            maxCash = max(maxCash, dp[i]);
        }
        return maxCash;
    }
};

class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int start) {
        if (start >= nums.size()) return 0;

        if (memo[start] != -1) return memo[start];

        int res = max(dfs(nums, start + 1), nums[start] + dfs(nums, start + 2));
        memo[start] = res;
        return res;
    }
};
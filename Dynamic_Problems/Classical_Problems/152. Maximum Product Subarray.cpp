#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(2, INT_MIN));
        dp[0][1] = nums[0];
        dp[0][0] = nums[0];

        int maxPro = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                dp[i][1] = max(dp[i - 1][1] * nums[i], nums[i]);
                dp[i][0] = min(dp[i - 1][0] * nums[i], nums[i]);
            }else {
                dp[i][1] = max(dp[i - 1][0] * nums[i], nums[i]);
                dp[i][0] = min(dp[i - 1][1] * nums[i], nums[i]);
            }
            maxPro = max(maxPro, dp[i][1]);
        }
        return maxPro;
    }
};
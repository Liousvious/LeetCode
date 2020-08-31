#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int res = 0, maxLength = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
                maxLength = max(maxLength, dp[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (maxLength == dp[i]) res += count[i];
        }
        return res;
    }
};
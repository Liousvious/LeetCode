#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size()+1, 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int res = 1;
        for (int i = 0; i < dp.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution {
private:
    int maxLen = 1;
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        backTracking(nums, 0, 0, INT_MIN);
        return maxLen;
    }

    void backTracking(vector<int>& nums, int loc, int len, int pre) {
        unordered_map<int, int> hashNum;
        for (int i = loc; i < nums.size(); i++) {
            if (hashNum[nums[i]] != 0 || nums[i] < pre) continue;
            hashNum[nums[i]] = 1;
            backTracking(nums, i + 1, len + 1, nums[i]);
        }
        maxLen = max(maxLen, len);
    }
};
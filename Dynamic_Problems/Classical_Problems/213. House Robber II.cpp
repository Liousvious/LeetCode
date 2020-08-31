#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> memo1 (nums.size(), -1);
        vector<int> memo2 (nums.size(), -1);
        return max(dfs(nums, memo1, 0, nums.size() - 2), \
                    dfs(nums, memo2, 1, nums.size() - 1));
    }

    int dfs(vector<int>& nums, vector<int>& memo, int start, int end) {
        if (start > end) return 0;

        if (memo[start] != -1) return memo[start];

        int res = max(dfs(nums, memo, start + 1, end), \
                    dfs(nums, memo, start + 2, end) + nums[start]);
        memo[start] = res;
        return res;
    }
};
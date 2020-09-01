#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return true;
        }
        vector<vector<int>> dp(len, vector<int>(len));
        vector<int> preSum(len + 1);
        for (int i = 0; i < len; i++) {
            dp[i][i] = nums[i];
            preSum[i + 1] = preSum[i] + nums[i];
        }

        int sum = 0;
        for (int i = len - 2; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                sum = preSum[j + 1] - preSum[i];
                dp[i][j] = max(sum - dp[i + 1][j], sum - dp[i][j - 1]);
            }
        }
        return min(dp[0][len - 2], dp[1][len - 1]) <= preSum.back() / 2;
    }
};
/*
本题的一个关键在于状态的选取，dp[i][j] 表示区间 [i, j] 的一个最优策略，即从这个区间取可以获得的最大分数，由于A有先手，所以只考虑这种最优的
情况即可，每次都取对应区间的最大分数，即最优策略，最后对应地从区间[0, len - 2] 和 [1, len - 1]这两个区间进行选取，找到最坏的情况，由于A
先手，所以A可以先拿，对应地B在A选择后找最优的，且最坏的那种最优策略其分数应该小于总和的二分之一，如果都大于二分之一，则无论A怎么先选，都不会影响到B拿到最优的策略。则A一定不会获胜。
*/

class Solution {
public:
    vector<vector<int>> memo;
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() < 3) return true;
        vector<int> preSum(nums.size() + 1);
        memo = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        return min(dfsSearch(nums, preSum, 0, nums.size() - 2), \
                    dfsSearch(nums, preSum, 1, nums.size() - 1)) <= preSum.back() / 2;

    }

    int dfsSearch(vector<int>& nums, vector<int>& preSum, int i, int j) {
        if (i == j) return nums[i];

        if (memo[i][j] != -1) return memo[i][j];

        int sum = preSum[j + 1] - preSum[i];
        int res = max(sum - dfsSearch(nums, preSum, i + 1, j), \
                    sum - dfsSearch(nums, preSum, i, j - 1));
        memo[i][j] = res;
        return res;
    }
};
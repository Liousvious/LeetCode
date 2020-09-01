#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if ((sum) & 1) return false;
        vector<vector<int>> visited(nums.size(), vector<int>((sum >> 1) + 1, 0));
        return dfs(visited, sum >> 1, 0, nums);
    }   

    bool dfs(vector<vector<int>>& visited, int sum, int index, vector<int>& nums) {
        if (sum == 0) return true;
        if (sum < 0 || index >= nums.size()) return false;

        int& isVisited = visited[index][sum];
        if (isVisited) return isVisited == 1;
        isVisited = (dfs(visited, sum, index + 1, nums) || \
                            dfs(visited, sum - nums[index], index + 1, nums) ? 1 : -1);
        return isVisited == 1;
    } 
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum & 1 == 1) return false;
        sum = sum >> 1;
        //vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));
        vector<bool> dp(sum + 1, false);
        //for (int i = 0; i <= nums.size(); i++) dp[i][0] = true;
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= 0; j--) {
                if (j - nums[i] >= 0) 
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};


class Solution {
public:
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;
    // 和为奇数时，不可能划分成两个和相等的集合
    if (sum % 2 != 0) return false;
    int n = nums.size();
    sum = sum / 2;
    vector<vector<bool>> 
        dp(n + 1, vector<bool>(sum + 1, false));
    // base case
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j - nums[i - 1] < 0) {
               // 背包容量不足，不能装入第 i 个物品
                dp[i][j] = dp[i - 1][j]; 
            } else {
                // 装入或不装入背包
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j-nums[i-1]];
            }
        }
    }
    return dp[n][sum];
}
};
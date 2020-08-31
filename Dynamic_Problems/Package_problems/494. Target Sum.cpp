#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0, n=nums.size();
        for(int i=0; i<n; i++) sum+=nums[i];
        if(nums.empty() || sum<S || (sum+S) & 1) return 0;

        int sumPos= (sum+S)/2; 

        vector<int>dp(sumPos+1,0);
        dp[0]=1;

        for(int num: nums)
        {
            for(int i=sumPos; i>=num; i--)
            {
                dp[i]= dp[i]+dp[i-num];
            }
        }
        return dp[sumPos];
    }
};

class Solution {
public:
    int count = 0;
    vector<vector<int>> memo;
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        backTracking(nums, 0, 0, S);
        return count;
    }

    void backTracking(vector<int>& nums, int i, int sum, int S) {
        if (i == nums.size()) {
            if (sum == S) count++;
        }else {
            backTracking(nums, i + 1, sum + nums[i], S);
            backTracking(nums, i + 1, sum - nums[i], S);
        }
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) { 
        if (nums.size() == 0) return 0;

        vector<vector<int>>dp(nums.size(), vector<int>(2, 0));
        dp[0][1] = nums[0] > 0 ? 1 : 0;
        dp[0][0] = nums[0] < 0 ? 1 : 0;
        int maxLen = dp[0][1];
        
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] > 0){
                dp[i][1] = dp[i - 1][1] + 1;
                dp[i][0] = dp[i - 1][0] > 0 ? dp[i - 1][0] + 1 : 0;
            }
            else if(nums[i] < 0){
                dp[i][1] = dp[i - 1][0] > 0 ? dp[i - 1][0] + 1 : 0;
                dp[i][0] = dp[i - 1][1] + 1;
            }
            else{
                dp[i][1] = 0 ;
                dp[i][0] = 0 ;
            }
            maxLen = max(maxLen, dp[i][1]);
        }
        return maxLen;
    }
};
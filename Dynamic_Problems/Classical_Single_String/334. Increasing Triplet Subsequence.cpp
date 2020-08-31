#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> dp(nums.size() + 1, 1);
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {    
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int res = 1;
        for (int i = 0; i < dp.size(); i++) {
            res = max(res, dp[i]);
        }
        return res >= 3;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;

        for (auto e : nums) {
            if (e <= a) a = e;
            else if (e <= b) b = e;
            else return true;
        }
        return false;
    }
};
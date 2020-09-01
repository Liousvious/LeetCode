#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal) return false;
        vector<int> dp(1 << maxChoosableInteger, 2);
        return backTracking(maxChoosableInteger, desiredTotal, dp, 0);
    }

    bool backTracking(int maxChoosableInteger, int desiredTotal, vector<int>& dp, int state) {
        if (dp[state] < 2) return dp[state] == 1;

        for (int i = 1; i <= maxChoosableInteger; i++) {
            int cur = 1 << (i - 1);
            if (cur & state) continue;
            if (desiredTotal - i <= 0 || !backTracking(maxChoosableInteger, desiredTotal - i, dp, state | cur)) {
                dp[state] = 1;
                return true;
            }
        }
        dp[state] = 0;
        return false;
    }
};
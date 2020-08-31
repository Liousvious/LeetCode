#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.empty()) return 0;

        vector<vector<int>> dp(A.size() + 1, vector<int>(2));

        dp[1][1] = 1;
        dp[1][0] = 1;

        int maxLen = dp[1][1];

        for (int i = 2; i <= A.size(); i++) {
            if (A[i - 2] < A[i - 1]) {
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = 1;
            }else if (A[i - 2] > A[i - 1]) {
                dp[i][1] = 1;
                dp[i][0] = dp[i - 1][1] + 1;
            }else {
                dp[i][1] = 1;
                dp[i][0] = 0;
            }
            maxLen = max(maxLen, max(dp[i][1], dp[i][0]));
        }

        return maxLen;
    }
};
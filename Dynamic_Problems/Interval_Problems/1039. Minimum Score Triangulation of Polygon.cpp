#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int>& A) {
        if (A.size() < 3) return 0;
        dp = vector<vector<int>>(A.size(), vector<int>(A.size(), INT_MAX));
        return minScore(A, 0, A.size() - 1);
    }

    int minScore(vector<int>& A, int i, int j) {
        if (j - i < 2) return 0;
        
        if (dp[i][j] != INT_MAX) return dp[i][j];
        for (int k = i + 1; k < j; k++) {
            dp[i][j] = min(dp[i][j], minScore(A, i, k) + minScore(A, k, j) + A[i]*A[k]*A[j]);
        }
        return dp[i][j];
    }
};

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<vector<int>> dp(A.size(), vector<int>(A.size()));
        for (int len = 2; len < A.size(); len++) {
            for (int i = 0; i < A.size() - len; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
                }
            }
        }
        return dp[0][A.size() - 1];
    }
};
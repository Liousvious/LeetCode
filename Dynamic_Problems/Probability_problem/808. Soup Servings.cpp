#include <bits/stdc++.h>

using namespace std;

/**
 * @author zhang
 * dp[i][j]表示:当给定i毫升的A和j毫升的B的概率
 * 可知道dp[i][j]的概率=0.25*(dp[i-100][j]+dp[i-75][j-25]+dp[i-50][j-50]+dp[i-75][j-25])
 * 为了减小dp的大小，将其/25，如-1对应-25，并且<0的按照0来算
 */
class Solution {
public:
    double soupServings(int N) {
        if (N > 4800) return 1;
        int _N = (int)ceil(N / 25.0);

        vector<vector<double>> dp(_N + 1, vector<double>(_N + 1, 0));
        dp[0][0] = 0.5;

        for (int i = 1; i < _N + 1; i++) {
            dp[i][0] = 0;
            dp[0][i] = 1;
        }

        for (int i = 1; i < _N + 1; i++) {
            int a1 = i - 4 > 0 ? i - 4 : 0;
            int a2 = i - 3 > 0 ? i - 3 : 0;
            int a3 = i - 2 > 0 ? i - 2 : 0;
            int a4 = i - 1 > 0 ? i - 1 : 0;
            for (int j = 1; j < _N + 1; j++) {
                int b1 = j;
                int b2 = j - 1 > 0 ? j - 1 : 0;
                int b3 = j - 2 > 0 ? j - 2 : 0;
                int b4 = j - 3 > 0 ? j - 3 : 0;
                dp[i][j] = 0.25 * (dp[a1][b1] + dp[a2][b2] + dp[a3][b3] + dp[a4][b4]);
            }
        }
        return dp[_N][_N];
    }
};
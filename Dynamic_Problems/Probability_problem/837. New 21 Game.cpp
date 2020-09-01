#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1.0;
        }
        vector<double> dp(K + W);
        for (int i = K; i <= N && i < K + W; i++) {
            dp[i] = 1.0;
        }
        dp[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        }
        return dp[0];
    }
};

// https://leetcode-cn.com/problems/new-21-game/solution/xin-21dian-by-leetcode-solution/
// https://leetcode-cn.com/problems/new-21-game/solution/zen-yang-de-dao-guan-fang-ti-jie-zhong-de-zhuang-t/
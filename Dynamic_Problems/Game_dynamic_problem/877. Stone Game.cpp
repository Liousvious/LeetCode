#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        if (piles.size() < 3) return true;
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size()));
        vector<int> preSum(piles.size() + 1);
        for (int i = 0; i < piles.size(); i++) {
            dp[i][i] = piles[i];
            preSum[i + 1] = preSum[i] + piles[i];
        }

        int sum = 0;
        for (int i = piles.size() - 2; i >=0; i--) {
            for (int j = i + 1; j < piles.size(); j++) {    
                sum = preSum[j + 1] - preSum[i];
                dp[i][j] = max(sum - dp[i + 1][j], sum - dp[i][j - 1]);
            }
        }
        return min(dp[0][piles.size() - 2], dp[1][piles.size() - 1]) <= preSum.back() / 2;
    }
};

class Solution {
public:
    vector<vector<int>> memo;
    bool stoneGame(vector<int>& piles) {
        if (piles.size() < 3) return true;
        vector<int> preSum(piles.size() + 1);
        memo = vector<vector<int>>(piles.size(), vector<int>(piles.size(), 0));
        for (int i = 0; i < piles.size(); i++)
            preSum[i + 1] = preSum[i] + piles[i];
        return min(dfs(piles, preSum, 0, piles.size() - 2), \
                    dfs(piles, preSum, 1, piles.size() - 1)) <= preSum.back() / 2 ; 
    }

    int dfs(vector<int>& piles, vector<int>& preSum, int i, int j) {
        if (i == j) return piles[i];

        if (memo[i][j] != 0) return memo[i][j];

        int sum = preSum[j + 1] - preSum[i];
        return memo[i][j] = max(sum - dfs(piles, preSum, i + 1, j), \
                        sum - dfs(piles, preSum, i, j - 1));
    }
};
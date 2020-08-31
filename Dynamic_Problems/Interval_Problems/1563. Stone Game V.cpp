#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxScore = 0;
    vector<vector<int>> memo;
    int stoneGameV(vector<int>& stoneValue) {
        int i = 0, j = stoneValue.size() - 1;
        memo = vector<vector<int>>(stoneValue.size(), vector<int>(stoneValue.size(), 0));
        vector<int> preSum(stoneValue.size() + 1, 0);
        for (int i = 0; i < stoneValue.size(); i++) {
            preSum[i + 1] = preSum[i] + stoneValue[i];
        }
        return calculate(stoneValue, preSum, 0, stoneValue.size() - 1);
    }
    
    int calculate(vector<int>& stoneValue, vector<int>& preSum, int i, int j) {
        if (i == j) return 0;
        
        if (memo[i][j] != 0) return memo[i][j];
        
        int res = 0;
        for (int k = i; k < j; k++) {
            int preSum_1 = preSum[k + 1] - preSum[i];
            int preSum_2 = preSum[j + 1] - preSum[k + 1];
            int leftScore = calculate(stoneValue, preSum, i, k);
            int rightScore = calculate(stoneValue, preSum, k + 1, j);
            if (preSum_1 < preSum_2) {
                res = max(res, leftScore + preSum_1);
            }else if (preSum_1 > preSum_2) {
                res = max(res, rightScore + preSum_2);
            }else {
                res = max(res, leftScore > rightScore ? leftScore + preSum_1 : \
                                rightScore + preSum_2);
            }
        }
        memo[i][j] = res;
        return res;
    }
};
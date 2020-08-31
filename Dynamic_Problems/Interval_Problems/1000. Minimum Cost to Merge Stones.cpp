#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int INF = 0x3f3f3f3f;
    int _K;
    vector<int> preSum;
    vector<vector<vector<int>>> dp;
    int mergeStones(vector<int>& stones, int K) {
        if (stones.size() == 1) return 0;
        else if (stones.size() < K) return -1;

        _K = K;
        preSum = vector<int> (stones.size());
        preSum[0] = stones[0];
        for (int i = 1; i < stones.size(); i++) {
            preSum[i] = preSum[i - 1] + stones[i];
        }

        dp = vector<vector<vector<int>>> (stones.size(), vector<vector<int>> \
                                        (stones.size(), vector<int>(K + 1)));
        int res = mergeProcess(0, stones.size() - 1, 1);
        return res < INF ? res : -1;
    }

    int sumOfSubArr(int i, int j) {
        return i == 0 ? preSum[j] : preSum[j] - preSum[i - 1]; 
    }

    int mergeProcess(int i, int j, int k) {
        if (dp[i][j][k] != 0) return dp[i][j][k];

        if (j - i + 1 < k) return INF;
        else if (j - i + 1 == k) return 0;

        if (k == 1) {
            dp[i][j][k] = mergeProcess(i, j, _K) + sumOfSubArr(i, j);
            return dp[i][j][k];
        }
        
        dp[i][j][k] = INF;
        for (int t = i; t < j; t++) {
            dp[i][j][k] = min(dp[i][j][k], mergeProcess(i, t, 1) + mergeProcess(t + 1, j, k - 1));
        }
        return dp[i][j][k];
    }
};

using namespace std;
int main(int argc, char **argv) {
    int stone, K;
    vector<int> stones;
    while (cin >> stone && stone != '\n') {
        stones.push_back(stone);
    }
    cin >> K;
    Solution s;
    s.mergeStones(stones, K);
}
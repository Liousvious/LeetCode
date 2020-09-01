#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> memo;
    vector<int> postSum;
    int stoneGameII(vector<int>& piles) {
        memo = vector<vector<int>>(piles.size(), vector<int>(piles.size(), -1));
        postSum = vector<int> (piles.size());
        postSum[piles.size() - 1] = piles[piles.size() - 1];
        for (int i = piles.size() - 2; i >= 0; i--) {
            postSum[i] = postSum[i + 1] + piles[i];
        }
        return memorableDfs(piles, 0, 1);
    }

    int memorableDfs(vector<int>& piles, int start, int M) {
        if (piles.size() - start <= 2 * M) {
            memo[start][M] = postSum[start];
            return postSum[start];
        }

        if (memo[start][M] != -1) return memo[start][M];

        int res = 0;
        for (int i = 1; i <= 2 * M && start + i <= piles.size(); i++) {
            res = max(res, postSum[start] - memorableDfs(piles, start + i, max(M, i))); // 石子游戏假定第一个玩家和
                                                                                            //第二个玩家一样聪明
                                                                                    //因此都会在各自的回合进行最优的选取
        }
        memo[start][M] = res;
        return res;
    }

};
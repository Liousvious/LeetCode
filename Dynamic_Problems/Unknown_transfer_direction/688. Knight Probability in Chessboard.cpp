#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int dir[8][2] = {{1, 2}, {-1, 2}, {2, 1}, {-2, 1},
                    {1, -2}, {-1, -2} ,{2, -1} ,{-2, -1}};
    vector<vector<vector<double>>> memo;
    double knightProbability(int N, int K, int r, int c) {
        memo = vector<vector<vector<double>>> (N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        return memorableSearch(r, c, 0, N, K);
    }

    double memorableSearch(int row, int col, int step, int N, int K) {
        if (row < 0 || row >= N || col < 0 || col >= N) return 0.0;

        if (step >= K) return 1.0;

        if (abs(memo[row][col][step]) > 1e-6) {
            return memo[row][col][step];
        }

        double res = 0;
        for (int i = 0; i < 8; i++) {
            res += memorableSearch(row + dir[i][0], col + dir[i][1], step + 1, N, K) / 8;
        }
        memo[row][col][step] = res;
        return res;
    }
};
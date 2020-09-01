#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<vector<vector<int>>> memo;
    const int Mod = 1000000000 + 7;
    int findPaths(int m, int n, int N, int i, int j) {
        if (m == 0 || n == 0) return 0;
        memo = vector<vector<vector<int>>>(m + 2, vector<vector<int>>(n + 2, vector<int>(N + 2, -1)));
        return dfs(i, j, 0, N, m ,n);
    }

    int dfs(int row, int col, int step, int N, int m, int n) {
        if (step > N) return 0;

        if (!(row >= 0 && row < m && col >= 0 && col < n)) 
            return 1;
        
        if (memo[row][col][step] != -1)
            return memo[row][col][step];
            

        int res = 0;
        for (int i = 0; i < 4; i++) {
            res = (res + dfs(row + dir[i][0], col + dir[i][1], step + 1, N, m, n) % Mod) % Mod;
        }
        memo[row][col][step] = res;
        return res;
    }
};
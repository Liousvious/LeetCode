#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> memo;
    int maxLen = 1;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        memo = vector<vector<int>> (matrix.size(), vector<int>(matrix[0].size(), -1));

        int len = 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (memo[i][j] != -1) continue;
                len = memorableSearch(matrix, i, j, INT_MIN);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }

    int memorableSearch(vector<vector<int>>& matrix, int row, int col, int pre) {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] <= pre) 
            return 0;

        if (memo[row][col] != -1) return memo[row][col];

        int res = 1;
        int len = 1;
        for (int i = 0; i < 4; i++) {
            res = memorableSearch(matrix, row + dir[i][0], col + dir[i][1], matrix[row][col]) + 1;
            len = max(len, res);
        }

        memo[row][col] = len;
        return len;
    }
};

// class Solution {
// public:
//     int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& isVisited, int pre)
//     {
//         if(row<0 || col<0|| row>= matrix.size() || col>=matrix[0].size() || matrix[row][col]<=pre)
//             return 0;

//         //已经对该节点进行过求取，直接返回即可
//         if(isVisited[row][col] > 0)
//             return isVisited[row][col];

//         //遍历上下左右节点
//         int l = dfs(matrix, row, col-1, isVisited, matrix[row][col]);
//         int r = dfs(matrix, row, col+1, isVisited, matrix[row][col]);
//         int up = dfs(matrix, row-1, col, isVisited, matrix[row][col]);
//         int dow = dfs(matrix, row+1, col, isVisited, matrix[row][col]);

//         //存储以该节点为起点的最长增长序列的长度
//         isVisited[row][col] = 1 + max(max(l, r), max(up, dow));
//         return isVisited[row][col];
//     }
//     int longestIncreasingPath(vector<vector<int>>& matrix) 
//     {
//         int row = matrix.size();
//         if(row <= 0)return 0;
//         int col = matrix[0].size();

//         vector<vector<int>>isVisited(row, vector<int>(col, 0));
//         int res = 0;
//         //依次求取每一个节点为起点的最长增长序列，并保存最大值。
//         for(int i = 0; i < row; ++i)
//         {
//             for(int j = 0; j < col; ++j)
//                 res = max(res, dfs(matrix, i, j, isVisited, INT_MIN));
//         }
//         return res;
//     }
// };
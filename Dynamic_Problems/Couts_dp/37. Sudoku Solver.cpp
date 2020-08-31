#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool flag = backTracking(board, 0, 0);
        cout << flag << endl;
    }

    bool backTracking(vector<vector<char>>& board, int row, int col) {
        int m = 9, n = 9;
        if (col == n) {
            return backTracking(board, row + 1, 0);
        }

        if (row == m) return true;

        for (int i = row; i < m; i++) {
            for (int j = col; j < n; j++) {
                if (board[i][j] != '.') {
                    return backTracking(board, i, j + 1);
                }

                for (char ch = '1'; ch <= '9'; ch++) {
                    if (!isValid(board, i , j, ch)) continue;

                    board[i][j] = ch;
                    if (backTracking(board, i, j + 1)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int i, int j, char c) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c) return false;
            if (board[k][j] == c) return false;
            if (board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3] == c) return false;
        }
        return true;
    }
};
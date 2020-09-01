#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isValid(board, i, j, board[i][j])) return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (i != c && board[r][i] == ch) return false;
            if (i != r && board[i][c] == ch) return false;
            if (r != (r / 3) * 3 + i / 3 && c != (c / 3) * 3 + i % 3 && \
                 board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) 
                return false;
        }
        return true;
    }
};
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        vector<int> r(board.size(), 0);
        vector<int> c(board.size(), 0);
        vector<int> s(board.size(), 0);
        int count_1 = 0;
        int count_2 = 0;
        int win_count_1 = 0;
        int win_count_2 = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(board[i][j] == 'X') {
                    count_1++;
                    r[i]++;
                    c[j]++;
                    if (i == j) s[0]++;
                    if (i + j == 2) s[1]++;
                }else if (board[i][j] == 'O') {
                    count_2++;
                    r[i]--;
                    c[j]--;
                    if (i == j) s[0]--;
                    if (i + j == 2) s[1]--;
                }
                if (r[i] == 3 || s[0] == 3 || s[1] == 3 || c[j] == 3) win_count_1++;
                else if (r[i] == -3 || s[0] == -3 || s[1] == -3 || c[j] == -3) win_count_2++;
            }
        }
        cout << count_1 << " " << count_2 << " " << win_count_1 << " " << win_count_2 << endl;
        
        if (count_1 < count_2 || (count_1 - count_2) > 1 || ((count_1 == count_2) && (win_count_1 > 0)) ||\
            (win_count_1 > 0 && win_count_2 > 0) || (win_count_2 > 0 && count_1 > count_2 && win_count_1 == 0)) return false;
        return true;
    }
};
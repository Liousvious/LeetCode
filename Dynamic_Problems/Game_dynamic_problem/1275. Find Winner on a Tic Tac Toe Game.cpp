#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> r(3, 0);
        vector<int> c(3, 0);
        vector<int> s(2, 0);
        for (int i = 0; i < moves.size(); i++) {
            if (i % 2 == 0) {
                r[moves[i][0]]++;
                c[moves[i][1]]++;
                if (moves[i][0] == moves[i][1]) s[0]++;
                if (moves[i][0] + moves[i][1] == 2) s[1]++;
            }else {
                r[moves[i][0]]--;
                c[moves[i][1]]--;
                if (moves[i][0] == moves[i][1]) s[0]--;
                if (moves[i][0] + moves[i][1] == 2) s[1]--;
            }
            if (r[moves[i][0]] == 3 || c[moves[i][1]] == 3 || s[0] == 3 || s[1] == 3) return "A";
            else if (r[moves[i][0]] == -3 || c[moves[i][1]] == -3 ||s[0] == -3 || s[1] == -3) return "B";
        }
        if (moves.size() == 9) return "Draw";
        return "Pending";
    }
};
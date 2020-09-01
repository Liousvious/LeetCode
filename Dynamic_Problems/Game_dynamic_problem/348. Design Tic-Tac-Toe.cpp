#include <bits/stdc++.h>

using namespace std;


class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        r = vector<int>(n,0);
        c = vector<int>(n,0);
        s = vector<int>(2,0);
        length = n;
    }

    int move(int row, int col, int player) {
        if(player == 1){
            r[row]++;c[col]++;
            if(row == col){s[0]++;}
            if(row + col == length-1){s[1]++;}
        }else{
            r[row]--;c[col]--;
            if(row == col){ s[0]--;}
            if(row + col == length-1){ s[1]--;}
        }
        
        if(abs(r[row]) == length || abs(c[col]) == length||
           abs(s[0]) == length || abs(s[1]) == length){
            return player;
        }else{
            return 0;
        }
    }
private:
    vector<int> r;
    vector<int> c;
    vector<int> s;
    int length;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

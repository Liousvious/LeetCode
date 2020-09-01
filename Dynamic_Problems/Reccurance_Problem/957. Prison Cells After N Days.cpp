#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (!N) return cells;

        int n = N % 14;

        if (!n) n = 14;

        vector<int> preCells(cells);
        vector<int> curCells(8, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < cells.size(); j++) {
                if (j == 0 || j == cells.size() - 1) {
                    curCells[j] = 0;
                    continue;
                }
                if ((preCells[j - 1] == 1 && preCells[j + 1] == 1) || \
                    (preCells[j - 1] == 0 && preCells[j + 1] == 0)) {
                    curCells[j] = 1;
                }else {
                    curCells[j] = 0;
                }
            }
            preCells = curCells;
        }
        return curCells;
    }
};

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (!N)
            return cells;
        int n = N % 14;
        if (!n)
            n = 14;
        while (n--) {
            vector<int> tmp = vector<int>(cells);
            for (int i = 1; i < 7; ++i)
                cells[i] = (tmp[i - 1] ^ !tmp[i + 1]);
            cells[0] = cells[7] = 0;
        }
        return cells;
    }
};
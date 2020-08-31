#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count = 0;
    int n, m;
    int step;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x_start, y_start;
        n = grid.size();
        m = grid[0].size();
        step = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    x_start = i;
                    y_start = j;
                }else if (grid[i][j] == 0) {
                    step++;
                }
            }
        }
        backTracking(grid, x_start, y_start, 0);
        return count;
    }

    void backTracking(vector<vector<int>>& grid, int i, int j, int steps) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1) return;
        if (grid[i][j] == 2) {
            if (steps == step) {
                count++;
            } 
            return;
        }

        grid[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            backTracking(grid, i + dir[k][0], j + dir[k][1], steps + 1);
        }
        grid[i][j] = 0;
    }    
};
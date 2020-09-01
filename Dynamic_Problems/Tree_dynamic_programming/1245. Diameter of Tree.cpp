#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLen = 0;
    int treeDiameter(vector<vector<int>> &edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adjacent(n);

        for (auto &e : edges) {
            adjacent[e[0]].push_back(e[1]);
            adjacent[e[1]].push_back(e[0]);
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (adjacent[i].size() == 1) {
                ret = max(ret, dfs(adjacent, - 1, i));
            }
        }
        return ret - 1;

    }

    int dfs(vector<vector<int>>& adjacent, int pre, int cur) {
        int ret = 0;

        for (auto &adj : adjacent[cur]) {
            if (adj != pre) {
                ret = max(ret, dfs(adjacent, cur, adj));
            }
        }
        return ret + 1;
    }
};
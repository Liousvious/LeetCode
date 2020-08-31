#include <bits/stdc++.h>

using namespace std;

// COMPLETE PACKAGE PROBLEM

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.size() == 0) return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string s : strs) {
            int zero_num = 0, one_nums = 0;
            for (char c : s) {
                if (c == '0') zero_num++;
                else one_nums++;
            }

            for (int i = m; i >= zero_num; i--) {
                for (int j = n; j >= one_nums; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zero_num][j - one_nums] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //if (strs.size() == 0) return 0;
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 1; i <= strs.size(); i++) {
            string s = strs[i - 1];
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }
        
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j - zeros >=0 && k - ones >= 0)
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};
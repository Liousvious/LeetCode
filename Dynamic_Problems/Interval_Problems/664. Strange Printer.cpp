#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.size() == 0) return 0;

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= s.size(); len++) {
            for (int i = 0; i + len - 1 < s.size(); i++) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j] + 1;
                for (int k = i + 1; k < j; k++) {
                    if (s[k] == s[i]) 
                        dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
                }
                if (s[i] == s[j]) 
                    dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            }
        }
        return dp[0][s.size() - 1];
    }
};


class Solution {
public:
    vector<vector<int>> dp;
    int strangePrinter(string s) {
        dp = vector<vector<int>> (s.size(), vector<int>(s.size(), -1));
        return minPrint(s, 0, s.size() - 1);
    }

    int minPrint(string s, int i, int j) {
        if (i > j) return 0;
        else if (i == j) return 1;

        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = minPrint(s, i + 1, j) + 1;
        for (int k = i + 1; k < j; k++) {
            if (s[i] == s[k]) dp[i][j] = min(dp[i][j], minPrint(s, i + 1, k) + minPrint(s, k + 1, j));
        }
        if (s[i] == s[j]) dp[i][j] = min(dp[i][j], minPrint(s, i + 1, j));
        return dp[i][j];
    }
};
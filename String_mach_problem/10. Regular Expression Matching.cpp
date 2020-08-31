#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (!s.empty() && p.empty()) return false;
        if (s.empty() && p.empty()) return true;
        int len_s = s.size(), len_p = p.size();
        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= len_p; j++) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }

        for (int i = 1; i <= len_s; i ++) {
            for (int j = 1; j <= len_p; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j - 2] | dp[i - 1][j - 2] | dp[i - 1][j];
                    }else {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[len_s][len_p];
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0 && s.size() == 0) return true;
        vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++) {
            if (p[i - 1] != '*') break;
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= p.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') 
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
        }
        return dp[p.size()][s.size()];
    }
};
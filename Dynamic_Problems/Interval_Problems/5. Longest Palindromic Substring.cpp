#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        dp[0][0] = true;
        int maxLen = 1, begin = 0;
        for (int i = 1; i < s.size(); i++) {
            dp[i][i] = true;
            if (s[i - 1] == s[i]) {
                maxLen = max(maxLen, 2);
                begin = i - 1;
                dp[i - 1][i] = true;
            }
        } 

        for (int j = 2; j < s.size(); j++) {
            for (int i = j - 2; i >= 0; i--) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        begin = i;
                    }
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
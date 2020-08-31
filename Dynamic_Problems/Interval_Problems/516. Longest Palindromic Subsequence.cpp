#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() == 0) return 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j ++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size() - 1];
    }
};

class Solution {
public:
    vector<vector<int>> memo;
    int longestPalindromeSubseq(string s) {
        memo = vector<vector<int>> (s.size(), vector<int>(s.size(), -1)); 
        return dfs(s, 0, s.size() - 1);
    }

    int dfs(string s, int i, int j) {
        if (j < i) return 0;
        if (i == j) return 1;
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == s[j]) memo[i][j] = dfs(s, i + 1, j - 1) + 2;
        else memo[i][j] = max(dfs(s, i + 1, j), dfs(s, i, j - 1));
        return memo[i][j];
    }
};
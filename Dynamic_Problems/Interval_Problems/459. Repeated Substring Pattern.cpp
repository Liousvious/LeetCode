#include <bits/stdc++.h>

using namespace std;


// class KMP {
// public:
//     vector<vector<int>> dp;
//     string pat;
//     KMP (string pat) {
//         this->pat = pat;
//         int M = pat.size();
//         dp = vector<vector<int>>(M, vector<int>(256, 0));

//         dp[0][pat[0]] = 1;
//         int shadow = 0;
//         for (int j = 1; j < M; j++) {
//             for (int c = 0; c < 256; c++) {
//                 dp[j][c] = dp[shadow][c];
//             }
//             dp[j][pat[j]] = j + 1;
//             shadow = dp[shadow][pat[j]];
//         }
//     }

//     int search(string txt) {
//         int M = pat.size();
//         int N = txt.size();
//         int j = 0;
//         for (int i = 0; i < N; i++) {
//             j = dp[j][txt[i]];
//             if (j == M) return i - M + 1;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int M = s.size();
        
        vector<vector<int>> dp(M, vector<int>(124, 0));
        dp[0][s[0]] = 1;
        int shadow = 0;
        
        for (int i = 1; i < M; i++) {
            for (int c = 97; c < 123; c++) {
                dp[i][c] = dp[shadow][c];
            }
            dp[i][s[i]] = i + 1;
            shadow = dp[shadow][s[i]];
        }
        if (shadow == 0) return false;
        return shadow % (M - shadow) == 0;

    }
};
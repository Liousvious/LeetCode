#include <bits/stdc++.h>

using namespace std;

class KMP {
public:
    vector<vector<int>> dp;
    string pat;
    KMP(string pat) {
        this->pat = pat;
        int M = pat.size();

        dp = vector<vector<int>> (M, vector<int>(123, 0));
        int shadow = 0;
        dp[0][pat[0]] = 1;
        for (int j = 1; j < M; j++) {
            for (int c = 97; c < 123; c++) {
                dp[j][c] = dp[shadow][c];
            }
            dp[j][pat[j]] = j + 1;
            shadow = dp[shadow][pat[j]];
        }
    }

    int search(string str) {
        int N = str.size();
        int M = pat.size();
        int j = 0;
        for (int i = 0; i < N; i++) {
            j = dp[j][str[i]];
            if (j == M) return i - M + 1;
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;

        KMP* kmp = new KMP(needle);
        int pos = kmp->search(haystack);
        return pos;
    }
};
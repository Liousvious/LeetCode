#include <bits/stdc++.h>

using namespace std;


// TLE

class KMP {
public:
    vector<vector<int>> dp;
    string pat;
    KMP (string pat) {
        this->pat = pat;
        int M = pat.size();
        dp = vector<vector<int>>(M, vector<int>(256, 0));

        dp[0][pat[0]] = 1;
        int shadow = 0;
        for (int j = 1; j < M; j++) {
            for (int c = 0; c < 256; c++) {
                dp[j][c] = dp[shadow][c];
            }
            dp[j][pat[j]] = j + 1;
            shadow = dp[shadow][pat[j]];
        }
    }

    int search(string txt) {
        int M = pat.size();
        int N = txt.size();
        int j = 0;
        for (int i = 0; i < N; i++) {
            j = dp[j][txt[i]];
            if (j == M) return i - M + 1;
        }
        return -1;
    }
};

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string str;
        int len_A = A.size();
        int len_B = B.size();
        KMP* kmp = new KMP(B);
        int pos = -1;
        int count = 1;
        while (len_A < len_B) {
            str += A;
            count++;
        }
        while (pos != -1) {
            pos = kmp->search(str);
            str += A;
            count++;
        }
        return count;
    }
};
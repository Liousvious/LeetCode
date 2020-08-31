#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dp[1000][1000];
    int countSubstrings(string s) {
        int size = s.size();
        dp[0][0] = true;
        for(int i = 1; i < size; i++){
            dp[i][i] = true;
            if(s[i-1] == s[i]){
                dp[i-1][i] = true;
            }
        }

        for (int j = 2; j < s.size(); j++) {
            for (int i = 0; i < j - 1; i++) {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            }
        }

        int sum = 0; //用 accumulate 函数计算总和
        for(const auto & v : dp)
            sum = accumulate(v, v + size, sum);
        return sum;
    }
};
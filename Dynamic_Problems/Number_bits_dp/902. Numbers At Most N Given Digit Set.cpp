#include <bits/stdc++.h>

using namespace std;

/*
    dp[i][0] denotes the total combination numbers equal to target number last i bits
    
    dp[i][1] denotes the total combination numbers less than target number last i bits

*/


class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string target = to_string(N);

        int res = 0;
        int len = target.size();
        int size = D.size();

        vector<vector<int>> dp(len + 1, vector<int>(2, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= len; i++) {
            string num = string("") + target[i - 1];

            vector<string>::iterator it = lower_bound(D.begin(), D.end(), num);

            if (it != D.end()) {
                if (*it == num && dp[i - 1][0] == 1) {
                    dp[i][0] = 1;
                }
            }

            dp[i][1] = (it - D.begin()) * dp[i - 1][0] + dp[i - 1][1] * size;
            dp[i][1]++;
        }
        res = dp[len][1] + dp[len][0] - 1;
        return res;
    }
};
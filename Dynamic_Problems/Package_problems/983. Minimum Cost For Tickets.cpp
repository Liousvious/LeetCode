#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int len = days.size(), maxDay = days[len - 1], minDay = days[0];
        vector<int> dp(maxDay + 31);
        for (int d = maxDay, i = len - 1; d >= minDay; d--) {
            if (d == days[i]) {
                dp[d] = min(dp[d + 1] + costs[0], dp[d + 7] + costs[1]);
                dp[d] = min(dp[d], dp[d + 30] + costs[2]);
                i--;
            }else {
                dp[d] = dp[d + 1];
            }
        }
        return dp[minDay];
    }
};
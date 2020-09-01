#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, int> memo;
    int dp(int K, int N) {
        if (memo.find(100 * N + K) == memo.end()) {
            int ans;
            if (N == 0) ans = 0;
            else if (K == 1) ans = N;
            else {
                int low = 1, high = N;
                while (low + 1 < high) {
                    int mid = low + (high - low) / 2;
                    int t1 = dp(K - 1, mid - 1);
                    int t2 = dp(K, N - mid);
                    if (t1 < t2) low = mid;
                    else if (t1 > t2) high = mid;
                    else low = high = mid;
                }    
                ans = 1 + min(max(dp(K - 1, low - 1), dp(K, N - low)), max(dp(K - 1, high - 1), dp(K, N - high)));
            }
            memo[N * 100 + K] = ans;
        }
        return memo[N * 100 + K];
    }
        
public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};

class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[N + 1];
        for (int i = 0; i <= N; i++) {
            dp[i] = i;
        }

        for (int k = 2; k <= K; ++k) {
            int dp2[N + 1];
            int x = 1;
            dp2[0] = 0;
            for (int n = 1; n <= N; ++n) {
                while (x < n && max(dp[x - 1], dp2[n -  x]) >= max(dp[x], dp2[n - x - 1])) ++x;
                dp2[n] = 1 + max(dp[x - 1], dp2[n - x]);
            }
            for (int n = 1; n <= N; ++n) dp[n] = dp2[n];
        }
        return dp[N];
    }
};
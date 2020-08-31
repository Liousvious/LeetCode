#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> memo;
    int numTrees(int n) {
        return memorableDfs(1, n);
    }

    int memorableDfs(int begin, int end) {
        if (begin > end) return 1;
        
        if (memo.count(end - begin) > 0) return memo[end - begin];

        int sum = 0;
        for (int i = begin; i <= end; i++) {
            int left = memorableDfs(begin, i - 1);
            int right = memorableDfs(i + 1, end);
            sum += left * right;
        }
        memo[end - begin] = sum;
        return sum;
    }
};
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int preSum = 0;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int maxEle = INT_MIN, sum = 0;
        unordered_map<int, int> hashMap;
        for (int num : nums) {
            hashMap[num]++;
            sum += num;
            maxEle = max(maxEle, num);
        }
        if (sum % k) return false;
        preSum = sum / k;
        if (preSum < maxEle) return false;
        return dfs(hashMap, k, 0);
    }

    bool dfs(unordered_map<int, int>& hashMap, int nowK, int target) {
        if (target == 0) {
            if (nowK == 0) return true;
            else return dfs(hashMap, nowK - 1, preSum);
        }else {
            for (int num = target; num > 0; num--) {
                if (hashMap.count(num) && hashMap[num] > 0) {
                    hashMap[num]--;
                    if (dfs(hashMap, nowK, target - num)) return true;
                    hashMap[num]++;
                }
            }
            return false;
        }
    }
};
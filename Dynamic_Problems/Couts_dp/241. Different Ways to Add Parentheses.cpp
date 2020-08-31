#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c =='+' || c == '-' || c == '*') {
                auto res1 = diffWaysToCompute(input.substr(0, i));
                auto res2 = diffWaysToCompute(input.substr(i + 1));
                for (auto r1 : res1) {
                    for (auto r2 : res2) {
                        if (c == '+') {
                            res.push_back(r1 + r2);
                        }else if (c == '-') {
                            res.push_back(r1 - r2);
                        }else if (c == '*') {
                            res.push_back(r1 * r2);
                        }
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};
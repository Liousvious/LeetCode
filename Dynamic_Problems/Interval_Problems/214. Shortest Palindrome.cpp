#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        if (isPalindrome(s)) return s;
        queue<char> queue;
        string str, res;
        for (int i = s.size() - 1; i >= 0; i--) {
            queue.push(s[i]);
            str = s.substr(0, i);
            if (isPalindrome(str)) break;
        }

        while (!queue.empty()) {
            res += queue.front();
            queue.pop();
        }
        return res + s;
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        string s_reverse(s), s_new;
        reverse(s_reverse.begin(), s_reverse.end());
        s_new = s + "$" + s_reverse;
        int i = -1, j = 0;
        vector<int> next(s_new.size() + 1, 0);
        next[0] = -1;
        while (j < s_new.size()) {
            if (i == -1 || s_new[i] == s_new[j]) {
                i++;
                j++;
                next[j] = i;
            }else {
                i = next[i];
            }
        }
        return s_new.substr(s.size() + 1, s.size() - next[s_new.size()]) + s;
    }
};
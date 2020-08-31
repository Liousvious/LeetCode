#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    int result = 0;
    int countArrangement(int N) {
        visited = vector<bool>(N, false);
        backTracking(1, N);
        return result;
    }

    void backTracking(int index, int N) {
        if (index > N) {
            result++;
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (i % index == 0 || index % i == 0)) {
                visited[i] = true;
                backTracking(index + 1, N);
                visited[i] = false;
            }
        }
    }
};
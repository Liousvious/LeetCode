#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    string tWord;
    Trie* child[26];
public:
    Trie () {
        tWord = "";
        memset(child, 0, sizeof(child));
    }

    void insert(string word) {
        Trie* curNode = this;
        for (char c : word) {
            if (curNode->child[c - 'a'] == NULL) {
                curNode->child[c - 'a'] = new Trie();
            }
            curNode = curNode->child[c - 'a'];
        }
        curNode->tWord = word;
    }

    void dfsSearch(vector<vector<char>>& board, Trie* trie, int i, int j, vector<string>& res) {
        char c = board[i][j];
        // DFS边界条件
        if (c == '*' || trie->child[c - 'a'] == NULL) return;
        trie = trie->child[c - 'a'];
        if (trie->tWord != "") {
            res.push_back(trie->tWord);
            trie->tWord = "";
        }
        board[i][j] = '*'; // 回溯法需要先假定该种情况下为真
        // 回溯法和传统的DFS算法本质上不同的地方，即对每个回溯的过程进行判断，当不满足时返回断点进行下一种情况的操作
        // 回溯法的基本思想也是需要在每一步对下一步的所有情况进行枚举以进行遍历，当不满足时便会返回当前断点，同时也为了避免过多
        // 重复操作，也需要剪枝，及上述的board[i][j]
        if (i > 0) 
            dfsSearch(board, trie, i - 1, j, res);
        if (j > 0) 
            dfsSearch(board, trie, i, j - 1, res);
        if (i < board.size() - 1) 
            dfsSearch(board, trie, i + 1, j, res);
        if (j < board[0].size() - 1) 
            dfsSearch(board, trie, i, j + 1, res);
        board[i][j] = c; // 当所有的情况都不满足时需要回退
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int rows = board.size();
        int columns = board[0].size();
        if (rows == 0 || columns == 0) {
            return res;
        }

        Trie* trie = new Trie();
        for (string word : words) {
            trie->insert(word);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                trie->dfsSearch(board, trie, i, j, res);
            }
        }
        return res;
    }
};
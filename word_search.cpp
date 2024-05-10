//time O(n 3^l)
//space O(l)
class Solution {
public:
    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, -1, 1};

    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j,
             int m, int n) {
        
        if (index == word.size()) {
            return true;
        }
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0) {
            return false;
        }
        if (board[i][j] != word[index]) {
            return false;
        }
        board[i][j] = '#';

        // Recursively search in all four directions from the current cell
        for (int k = 0; k < 4; k++) {
            if(dfs(board, word, index + 1, i+r[k], j+c[k], m, n))
                 return true; // If the word is found, return true
        }

        board[i][j] = word[index];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

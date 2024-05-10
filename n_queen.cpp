//Time O(n!)
//Space O(n^2)

class Solution {
public:
    bool isSafe(int row, int n, vector<string>& slate, int col) {
        // Check if there is any conflict in slates above this one

       
        int cur_row = row;
        int cur_col = col;
        //diagonal check
        while (cur_row >= 0 && cur_col >= 0) {
            if (slate[cur_row--][cur_col--] == 'Q') {
                return false;
            }
        }
        // Check column.
        cur_row = row;
        while (cur_row >= 0) {
            if (slate[cur_row--][col] == 'Q') {
                return false;
            }
        }
        // Check the "slash" diagonal.
        cur_row = row, cur_col = col;
        while (cur_row >= 0 && cur_col < n) {
            if (slate[cur_row--][cur_col++] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void helper(int row, int n, vector<string>& slate,
                vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(slate);
            return;
        }
        // recursive case
        for (int col = 0; col < n; col++) {
            if (isSafe(row, n, slate, col)) {
                slate[row][col] = 'Q';
                helper(row + 1, n, slate, ans);
                slate[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string empty_row(n, '.');
        vector<string> slate(n, empty_row);

        helper(0, n, slate, ans);
        return ans;
    }
};

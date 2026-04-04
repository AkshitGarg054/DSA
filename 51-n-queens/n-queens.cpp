class Solution {
public:
    vector<vector<string>> ans;

    bool isValid(int r, int c, vector<string> &temp, int n) {
        for(int i = 0; i < r; i++) if(temp[i][c] == 'Q') return false;
        for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++) if(temp[i][j] == 'Q') return false;
        for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) if(temp[i][j] == 'Q') return false;
        return true;
    }

    void solve(int row, int n, vector<string> &temp) {
        if(row == n) {
            ans.push_back(temp);
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isValid(row, col, temp, n)) {
                temp[row][col] = 'Q';
                solve(row + 1, n, temp);
                temp[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        solve(0, n, temp);
        return ans;
    }
};
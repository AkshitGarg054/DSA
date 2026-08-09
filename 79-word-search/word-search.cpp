class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool dfs(int r, int c, int index, string &word, vector<vector<char>> &board) {
        if(index == word.size()) return true;

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited

        for(auto &d: dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(board[nr][nc] == '#') continue;
            if(board[nr][nc] == word[index]) {
                if(dfs(nr, nc, index + 1, word, board)) return true;
            }
        }

        board[r][c] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 1, word, board)) return true;
                }
            }
        }

        return false;
    }
};
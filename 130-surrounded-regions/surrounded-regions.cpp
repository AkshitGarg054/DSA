class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<char>>& board) {
        grid[r][c] = 1;

        for(auto &d: dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(board[nr][nc] == 'O' && grid[nr][nc] == 0) dfs(nr, nc, grid, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') dfs(0, j, grid, board);
            if(board[n - 1][j] == 'O') dfs(n - 1, j, grid, board);
        }

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') dfs(i, 0, grid, board);
            if(board[i][m - 1] == 'O') dfs(i, m - 1, grid, board);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 1 && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
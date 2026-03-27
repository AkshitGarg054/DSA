class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x = i, y = j;
                int live = 0, dead = 0;

                for(auto [dx, dy] : dirs) {
                    x = i + dx;
                    y = j + dy;

                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    if(board[x][y] == 0) dead++;
                    else live++;
                }

                if(live < 2 && board[i][j] == 1) ans[i][j] = 0;
                else if(board[i][j] == 1 && (live == 2 || live == 3)) ans[i][j] = 1;
                else if(board[i][j] == 1 && live > 3) ans[i][j] = 0;
                else if(board[i][j] == 0 && live == 3) ans[i][j] = 1;
                else ans[i][j] = 0;
            }
        }

        board = ans;
    }
};
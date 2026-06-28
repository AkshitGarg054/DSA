class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    int count_mines(int r, int c, vector<vector<char>>& board) {
        int count = 0;

        for(auto &d: dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(board[nr][nc] == 'M' || board[nr][nc] == 'X') count++;
        }

        return count;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size();
        m = board[0].size();
        int click_r = click[0], click_c = click[1];

        if(board[click_r][click_c] == 'M') {
            board[click_r][click_c] = 'X';
            return board;
        } 

        int mines = count_mines(click_r, click_c, board); // count the number of mines adjacent to click

        if(mines >= 1) {
            board[click_r][click_c] = mines + '0';
            return board;
        }

        // empty square 'E' with no adjacent mines is clicked
        board[click_r][click_c] = 'B';
        
        for(auto &d: dirs) {
            int nr = click_r + d[0];
            int nc = click_c + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(board[nr][nc] == 'M' || board[nr][nc] == 'E') {
                vector<int> next = {nr, nc};
                updateBoard(board, next);
            }
        }

        return board;
    }
};
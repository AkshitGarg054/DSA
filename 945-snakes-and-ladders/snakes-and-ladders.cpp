class Solution {
public:
    int n, m;

    int cell(int index, vector<vector<int>> &grid) {
        index = index - 1; // convert to 0-based indexing

        int row = index / m; // row from top
        int col = index % m; 
        if(row % 2 != 0) col = m - 1 - col;

        return grid[n - 1 - row][col]; // row from bottom
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();

        queue<int> q;
        q.push(1); 

        vector<int> vis(n*n + 1, 0);
        vis[1] = 1;

        int rolls = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int curr = q.front();
                q.pop();

                if(curr == n*n) return rolls;

                for(int i = curr + 1; i <= min(curr + 6, n*n); i++) {
                    if(vis[i]) continue;
                    vis[i] = 1;

                    if(cell(i, board) == -1) q.push(i);
                    else {
                        int value = cell(i, board);
                        q.push(value);
                    }
                }
            }

            rolls++;
        }

        return -1;
    }
};
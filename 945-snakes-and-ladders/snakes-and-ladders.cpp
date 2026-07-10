class Solution {
public:
    int n;

    int cell(int index, vector<vector<int>> &board) {
        if(index > n*n) return 1e9;
        index = index - 1; // for 0 based indexing 

        int row = index / n; // this is the row from top
        int col = index % n;
        if(row % 2 != 0) col = n - col - 1;

        return board[n - row - 1][col]; // (n - row - 1) is the row from bottom
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;

        queue<int> q; // current square
        q.push(1); // start position

        vector<int> vis(n*n + 1, 0);
        vis[1] = 1;

        while(!q.empty()) {
            int sz = q.size();
            
            while(sz--) {
                int curr = q.front();
                q.pop();

                if(curr == n*n) return steps;

                for(int i = 1; i <= 6; i++) {
                    int next = curr + i;
                    if(next > n*n) break;

                    int val = cell(next, board); // if there's a snake or ladder, then we must take it
                    if(val != -1) next = val;

                    if(!vis[next]) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
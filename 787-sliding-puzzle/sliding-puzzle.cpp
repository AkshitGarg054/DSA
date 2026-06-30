class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += (board[i][j] + '0');
            }
        }

        string goal = "123450";

        // valid moves for each index of '0'
        vector<vector<int>> list = {
            {1, 3}, // 0 --> if 0 is at 0th index, then it can go to 1 or 3 index
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<string> q;
        q.push(start);
        unordered_set<string> vis;
        vis.insert(start);

        int level = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string curr = q.front();
                q.pop();

                if(curr == goal) return level;

                int index = curr.find('0');

                for(auto &v: list[index]) {
                    swap(curr[v], curr[index]);
                    if(!vis.count(curr)) {
                        vis.insert(curr);
                        q.push(curr);
                    }

                    swap(curr[v], curr[index]); // undo (to continue to the next neighbor)
                }
            }

            level++;
        }

        return -1;
    }
};
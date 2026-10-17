class Solution {
public:
    const int MOD = 1e9 + 7;
    int rows, cols;
    vector<string> columnStates;
    vector<vector<int>> dp;

    void generateStates(int index, string &temp, int rows) {
        if(index == rows) {
            columnStates.push_back(temp);
            return;
        }

        for(auto ch: {'r', 'g', 'b'}) {
            if(!temp.empty() && temp.back() == ch) continue;
            temp += ch;
            generateStates(index + 1, temp, rows);
            temp.pop_back(); // backtrack
        }
    }

    int solve(int index, int col) {
        if(col == cols) return 1; // found one way to color the entire grid
        if(dp[index][col] != -1) return dp[index][col];

        string prevState = columnStates[index]; 
        int ways = 0;

        for(int i = 0; i < columnStates.size(); i++) {
            if(i == index) continue;
            string curr_candidate = columnStates[i];
            bool valid = true;

            for(int j = 0; j < rows; j++) {
                if(prevState[j] == curr_candidate[j]) {
                    valid = false;
                    break;
                }
            }

            if(valid) ways = (ways + solve(i, col + 1)) % MOD;   
        }

        return dp[index][col] = ways;
    }

    int colorTheGrid(int m, int n) {
        rows = m;
        cols = n;

        string temp = "";
        generateStates(0, temp, rows);

        dp.assign(columnStates.size(), vector<int>(cols, -1));

        int ways = 0;
        for(int i = 0; i < columnStates.size(); i++) { // we will run the solve() function for each initial state.
            ways = (ways + solve(i, 1)) % MOD; //  index_of_prev_state, curr_column_to_be_colored
        }

        return ways;
    }
};
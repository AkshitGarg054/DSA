class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = rows;
        int m = encodedText.size() / rows;

        vector<vector<char>> grid(n, vector<char>(m));

        for(int i = 0; i < encodedText.size(); i++) {
            int r = i / m;
            int c = i % m;
            grid[r][c] = encodedText[i];
        }

        string ans = "";

        // start from first row
        for(int col = 0; col < m; col++) {
            int i = 0, j = col;

            while(i < n && j < m) {
                ans += grid[i][j];
                i++, j++;
            }
        }

        // remove trailing spaces
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1 || numRows >= n) return s;

        vector<string> rows(numRows); // array of strings to represent each row
        int curr_row = 0;
        int dir = 1; // 1 for down, -1 for up

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            rows[curr_row].push_back(ch);

            if(curr_row == numRows - 1 && dir == 1) {
                curr_row--; 
                dir = -1;
            }
            else if(curr_row == 0 && dir == -1) {
                curr_row++;
                dir = 1;
            }
            else if(dir == 1) curr_row++;
            else if(dir == -1) curr_row--;
        }

        string ans = "";
        for(int i = 0; i < rows.size(); i++) {
            ans += rows[i];
        }

        return ans;
    }
};
class Solution {
public:
    // There are two condition that need to be taken care of :
    // open_count < n
    // and, close_count < open_count
    vector<string> ans;

    void solve(string temp, int open_count, int close_count, int n) {
        if(temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if(open_count < n) solve(temp + '(', open_count + 1, close_count, n);
        if(close_count < open_count) solve(temp + ')', open_count, close_count + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};
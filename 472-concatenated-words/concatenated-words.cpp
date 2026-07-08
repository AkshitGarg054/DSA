class Solution {
public:
    // The only approach i can think of is to check every word using "extend" and "new" method,
    // whether that word can be formed by the combination of other given words or not
    unordered_set<string> st;
    vector<vector<int>> dp;

    bool solve(int i, int j, string &word) {
        if(i >= word.size() && j >= word.size()) return true;
        if(j >= word.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];

        st.erase(word); // so that a word does not match to itself
        string sub = word.substr(i, j - i + 1);

        if(st.count(sub)) {
            if(solve(i, j + 1, word)) return dp[i][j] = true; // extend
            if(solve(j + 1, j + 1, word)) return dp[i][j] = true; // make new
        }
        else {
            if(solve(i, j + 1, word)) return dp[i][j] = true; // extend
        }

        st.insert(word); // undo
        return dp[i][j] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        for(auto &word: words) st.insert(word);

        for(int i = 0; i < n; i++) {
            string word = words[i];
            int m = word.size();

            dp.assign(m + 1, vector<int>(m + 1, -1));
            if(solve(0, 0, word)) ans.push_back(word);
        }

        return ans;
    }
};
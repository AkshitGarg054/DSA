class Solution {
public:
    unordered_set<string> st;

    bool solve(int index, string &s, vector<int> &dp) {
        if(index == s.size()) return true;
        if(dp[index] != -1) return dp[index];

        string temp = "";
        for(int i = index; i < s.size(); i++) {
            temp += s[i];
            if(st.count(temp)) {
                if(solve(i + 1, s, dp) == true) return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto word : words) st.insert(word);
        vector<string> ans;

        for(string word : words) {
            vector<int> dp(word.size(), -1);
        
            st.erase(word); // remove the word itself from the set
            if(solve(0, word, dp) == true) ans.push_back(word); 
            st.insert(word); // add the word back
        }

        return ans;
    }
};
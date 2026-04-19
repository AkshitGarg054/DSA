class Solution {
public:
    // A word is valid only if all its prefixes exist
    // example: "world" is valid because "w", "wo", "wor", "worl" all exist
    // algo :
    // sort the words array (important)
    // use a set to store valid words
    // For each word: check if removing last character exists in set (coz, if "worl" is valid, then "w", "wo", "wor" will already be valid)
    // If yes --> valid word
    // track the best answer

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());

        unordered_set<string> st;
        string ans = "";

        for(auto word : words) {
            bool valid = false;
            
            if(word.size() == 1) {
                st.insert(word); // always valid
                valid = true;
            }
            else if(st.count(word.substr(0, word.size() - 1))) {
                st.insert(word);
                valid = true;
            }
            
            if(valid && word.size() > ans.size()) ans = word; // keep the longest word
        }

        return ans;
    }
};
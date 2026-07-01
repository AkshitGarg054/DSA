class Solution {
public:
    // when split is at j:
    // prefix = word.substr(0, j)
    // suffix = word.substr(j)

    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) mp[words[i]] = i;

        for(int i = 0; i < n; i++) {
            string word = words[i];

            // try splitting each word at every possible index
            for(int j = 0; j <= word.size(); j++) {

                // if prefix is a palindrome
                if(isPalindrome(word, 0, j - 1)) {
                    string reversed_suffix = word.substr(j); // split at j
                    reverse(reversed_suffix.begin(), reversed_suffix.end());

                    if(mp.count(reversed_suffix) && mp[reversed_suffix] != i) {
                        ans.push_back({mp[reversed_suffix], i});
                    }
                }
                
                // j < size ensures suffix is non-empty, preventing duplicate pairs
                if(j < word.size() && isPalindrome(word, j, word.size() - 1)) { // if suffix is a palindrome
                    string reversed_prefix = word.substr(0, j);
                    reverse(reversed_prefix.begin(), reversed_prefix.end());

                    if(mp.count(reversed_prefix) && mp[reversed_prefix] != i) {
                        ans.push_back({i, mp[reversed_prefix]});
                    }
                }
            }
        }

        return ans;
    }
};
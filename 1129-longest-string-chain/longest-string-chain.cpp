class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        unordered_map<string, int> mp; // stores the length of longest chain till a word
        for(auto word: words) mp[word] = 1;

        sort(words.begin(), words.end(), [&](string &a, string &b) {
            return a.size() < b.size();
        });

        int maxi = 1;

        for(int i = 0; i < n; i++) {
            string word = words[i];
            int curr_maxi = mp[word];
            
            for(int j = 0; j < word.size(); j++) {
                string temp = word.substr(0, j) + word.substr(j + 1);
                if(mp.count(temp)) curr_maxi = max(curr_maxi, mp[temp] + 1);
            }

            mp[word] = curr_maxi;
            maxi = max(maxi, curr_maxi);
        }

        return maxi;
    }
};
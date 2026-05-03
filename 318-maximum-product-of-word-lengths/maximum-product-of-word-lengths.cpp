class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for(auto ch : words[i]) mp[ch]++;

            for(int j = i + 1; j < n; j++) {
                bool valid = true;
                
                for(auto ch : words[j]) {
                    if(mp.count(ch)) {
                        valid = false;
                        break;
                    }
                }
                
                if(valid) { 
                    int score = words[i].size() * words[j].size();
                    maxi = max(maxi, score);
                }
            }
        }

        return maxi;
    }
};
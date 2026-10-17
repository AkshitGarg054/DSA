class Solution {
public:
    int maxi = INT_MIN;
    vector<int> temp;

    bool possible(string word, vector<int> &vis, vector<char> &letters) {
        for(auto ch: word) {
            bool valid = false;
            for(int i = 0; i < letters.size(); i++) {
                if(letters[i] == ch && !vis[i]) {
                    valid = true;
                    vis[i] = 1;
                    break;
                }
            }
            if(valid == false) return false;
        }

        return true;
    }

    int calc(string word, vector<int> &score) {
        int ans = 0;
        for(auto ch: word) ans += score[ch - 'a'];
        return ans;
    }

    void solve(int index, vector<string> &words, vector<int> &vis, vector<char> &letters, vector<int> &score) {
        if(index == words.size()) {
            int total_score = accumulate(temp.begin(), temp.end(), 0);
            maxi = max(total_score, maxi);
            return;
        }

        vector<int> backup = vis;
        if(possible(words[index], vis, letters)) {
            int cost = calc(words[index], score);
            temp.push_back(cost);
            solve(index + 1, words, vis, letters, score);
            temp.pop_back(); // backtrack
        }
        vis = backup;

        solve(index + 1, words, vis, letters, score);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int l = letters.size();

        vector<int> vis(l, 0);
        solve(0, words, vis, letters, score); // word_index

        return maxi;
    }
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();

        // {index of word, index of current char in that word}
        vector<vector<pair<int, int>>> rooms(26, vector<pair<int, int>>());

        for(int i = 0; i < n; i++) {
            char first_char = words[i][0];
            rooms[first_char - 'a'].push_back({i, 0});
        }

        int count = 0;

        for(auto ch : s) {
            auto room = rooms[ch - 'a'];
            rooms[ch - 'a'].clear();

            for(auto &it : room) {
                int word_index = it.first;
                int next_char_index = it.second + 1;

                if(next_char_index == words[word_index].size()) count++;
                else {
                    char next_ch = words[word_index][next_char_index];
                    rooms[next_ch - 'a'].push_back({word_index, next_char_index});
                }
            }
        }

        return count;
    }
};
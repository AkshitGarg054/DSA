class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        int m = votes[0].size();

        unordered_map<char, vector<int>> mp; // char --> {freq at each position}
        for(auto ch: votes[0]) mp[ch] = vector<int>(m, 0); // initialize the vector for each char

        // populate the vector
        for(auto &voter: votes) {
            for(int i = 0; i < m; i++) {
                char ch = voter[i];
                mp[ch][i]++;
            }
        }

        vector<char> temp;
        for(int i = 0; i < votes[0].size(); i++) temp.push_back(votes[0][i]);

        sort(temp.begin(), temp.end(), [&](auto &a, auto &b) {
            for(int i = 0; i < m; i++) {
                if(mp[a][i] != mp[b][i]) return mp[a][i] > mp[b][i];
            }
            return a < b; // alphabatically smallest if tie
        });

        string ans = "";
        for(int i = 0; i < temp.size(); i++) ans += temp[i];
        return ans;
    }
};
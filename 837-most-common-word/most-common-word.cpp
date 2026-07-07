class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st;
        for(auto str: banned) st.insert(str);

        unordered_map<string, int> mp;
        string curr = "";

        // template to extract words from a normal string like:
        // "Bob hit a ball, the hit BALL flew far after it was hit."
        for(auto ch: paragraph) {
            if(isalpha(ch)) curr += ch;
            else if(!curr.empty()) {
                // convert curr to lowercase to count "ball" and "BALL" as same
                for(auto &c: curr) c = tolower(c); // notice &
                if(!st.count(curr)) mp[curr]++;
                curr.clear();
            }
        }

        if(!curr.empty()) { // insert last word
            for(char &c : curr) c = tolower(c);
            if(!st.count(curr)) mp[curr]++;
        }

        int maxi = INT_MIN;
        string ans;

        for(auto &[str, freq]: mp) {
            if(freq > maxi) {
                maxi = freq;
                ans = str;
            }
        }
        
        return ans;
    }
};
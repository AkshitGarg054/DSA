class Solution {
public:
    bool isValid(string &s, string &seq, int k) {
        int i = 0, j = 0;
        int count = 0;

        while(i < s.size()) {
            if(s[i] == seq[j]) {
                j++;
                if(j == seq.size()) {
                    j = 0;
                    count++;
                    if(count == k) return true;
                }
            }

            i++;
        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        
        vector<int> freq(26, 0);
        for(auto ch : s) freq[ch - 'a']++;

        string chars = "";
        for(int i = 0; i < 26; i++) {
            if(freq[i] >= k) chars += (char)('a' + i);
        }

        queue<string> q;
        q.push(""); // now, we will try to create different strings from chars string
 
        string ans = "";

        while(!q.empty()) {
            string curr = q.front();
            q.pop();

            for(char c : chars) {
                string next = curr + c;
                if(isValid(s, next, k)) {
                    ans = next; // incoming string will always be longer or equal to the prev ones
                    q.push(next);
                }
            }
        }

        return ans;
    }
};
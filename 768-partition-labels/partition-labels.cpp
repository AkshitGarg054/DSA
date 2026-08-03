class Solution {
public:
    // This seems very similar to jump game 2.
    // Let's say we encountered a char ch, then we need to iterate till the last ch in the string, 
    // and also keep seeing the range of inbetween elements, and have to choose the maximum one.

    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;

        unordered_map<char, int> mp; // stores the last position of every character
        for(int i = n-1; i >= 0; i--) {
            if(!mp.count(s[i])) mp[s[i]] = i;
        }

        int i = 0;
        while(i < n) {
            int limit = mp[s[i]];

            int j = i + 1;
            while(j < limit) {
                limit = max(limit, mp[s[j]]);
                j++;
            }

            ans.push_back(limit - i + 1);
            i = limit + 1;
        }

        return ans;
    }
};
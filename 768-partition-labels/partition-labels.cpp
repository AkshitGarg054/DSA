class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        for(int i = n-1; i >= 0; i--) {
            char ch = s[i];
            if(!mp.count(ch)) mp[ch] = i;
        }

        vector<int> ans;
        for(int i = 0; i < n; ) {
            int j = i;
            int maxi = mp[s[i]];

            while(j <= maxi) {
                maxi = max(maxi, mp[s[j]]);
                j++;
            }

            ans.push_back(maxi - i + 1);
            i = maxi + 1;
        }
        
        return ans;
    }
};
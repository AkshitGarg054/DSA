class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int result = 0;

        map<char, int> mp = {
            {'I', 1}, {'V', 5},   {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };

        for(int i=0; i < n; i++) {
            int value = mp[s[i]];
            if (i + 1 < n && mp[s[i]] < mp[s[i + 1]]) result -= value;
            else result += value;
        }

        return result;
    }
};
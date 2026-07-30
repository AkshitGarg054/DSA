class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        for(auto &ch: s) mp[ch]++;

        bool taken = false; // odd is taken or not
        int count = 0;

        for(auto &[ch, f]: mp) {
            if(f % 2 == 0) count += f;
            else {
                if(taken == false) {
                    count += f;
                    taken = true;
                }
                else count += (f - 1);
            }
        }

        return count;
    }
};
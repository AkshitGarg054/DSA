class Solution {
public:
    // like, we use a freq array of size 26 for lowercase letters,
    // similarly, we can use an ASCII freq array of size 128 for uppercase and lowercase English letters and digits.
    string frequencySort(string s) {
        int n = s.size();

        vector<int> freq(128, 0);   
        for(auto ch: s) freq[ch]++;

        vector<pair<int, char>> vec;
        for(int i = 0; i < 128; i++) {
            if(freq[i] > 0) vec.push_back({freq[i], (char)i});
        }

        sort(vec.begin(), vec.end(), greater<>());

        string ans = "";
        for(auto &[f, ch]: vec) ans += string(f, ch);
        return ans;
    }
};
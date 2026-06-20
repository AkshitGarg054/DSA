class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 0) return 0;

        auto expand_from_center = [&](int left, int right) {
            int count = 0;
            while(left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--, right++;
            }
            return count;
        };

        int odds = 0;
        int evens = 0;

        for(int i = 0; i < n; i++) {
            odds += expand_from_center(i, i);
            evens += expand_from_center(i, i + 1);
        }

        return odds + evens;
    }
};
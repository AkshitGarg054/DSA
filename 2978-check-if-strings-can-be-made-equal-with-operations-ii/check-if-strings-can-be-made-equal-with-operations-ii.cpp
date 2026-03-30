class Solution {
public:
    // j - i = even means,
    // a character at an even index can only go to another even index
    // a character at an odd index can only go to another odd index
    // So the string is basically split into 2 independent groups:
    // even-index characters, odd-index characters
    // and inside each group, you can permute freely.
    // So, Even positions of both strings should contain the same multiset of characters
    // and, Odd positions of both strings should contain the same multiset of characters

    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> even1(26, 0), odd1(26, 0);
        vector<int> even2(26, 0), odd2(26, 0);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            } else {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }

        return even1 == even2 && odd1 == odd2;
    }
};
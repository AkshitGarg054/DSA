class Solution {
public:
    // The input string s is already a palindrome so we know that at most one character will have an odd frequency.
    // To find the lexicographically smallest palindromic rearrangement, we need to build the palindrome from the outside in, placing the smallest alphabetical characters at the very beginning (and correspondingly at the very end).
    // Get the freq of every char.
    // To make the string lexicographically smallest, we iterate through our character counts in alphabetical order (from 'a' to 'z'). For every character, we take exactly half of its count and append it to our "first half" string.

    string smallestPalindrome(string s) {
        int n = s.size();

        vector<int> counts(26, 0);
        for(char ch: s) counts[ch - 'a']++;

        string first = "";
        string middle = "";

        for(int i = 0; i < 26; i++) {
            int freq = counts[i];
            if(counts[i] > 0) first += string(freq / 2, i + 'a');
            if(freq % 2 != 0) middle = string(1, i + 'a');
        }

        string last = first;
        reverse(last.begin(), last.end());

        return first + middle + last;
    }
};
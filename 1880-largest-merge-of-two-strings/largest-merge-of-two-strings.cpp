class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string merge = "";

        int i = 0, j = 0;
        while(i < n && j < m) {
            if(word1[i] > word2[j]) merge += word1[i++];
            else if(word1[i] < word2[j]) merge += word2[j++];
            else {
                if(word1.substr(i) > word2.substr(j)) merge += word1[i++];
                else merge += word2[j++];
            }
        }

        while(i < n) merge += word1[i++];
        while(j < m) merge += word2[j++];

        return merge;
    }
};
class Solution {
public:
    // NOTE : Whenever we get a stack overflow error, it means our program used too much stack memory and it crashed.
    // It usually happens due to :
    // 1. infinite recursion or due to,
    // 2. Allocating big arrays or objects locally, example : int arr[10000000];

    string largestMerge(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        string merge = "";
        int i = 0, j = 0;

        while(i < n && j < m) {
            if(word1[i] > word2[j]) {
                merge += word1[i];
                i++;
            }
            else if(word1[i] < word2[j]) {
                merge += word2[j];
                j++;
            }
            // this part is tricky. (i thought that two branches bnenge isme to recursion lgana pdega)
            // but always remember this trick of comparing the whole string in case of any confusion
            else if(word1.substr(i) > word2.substr(j)) {
                merge += word1[i];
                i++;
            }
            else {
                merge += word2[j];
                j++;
            }
        }

        if(i < n) merge += word1.substr(i);
        if(j < m) merge += word2.substr(j);

        return merge;
    }
};
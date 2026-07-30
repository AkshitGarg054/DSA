class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;

        int i = 0;

        while(i < n) {
            int sz = 0; // must needed space in a line
            int count = 0;  // count of words

            int j = i;
            while(j < n && sz + words[j].size() <= maxWidth) { 
                sz += words[j].size() + 1; // 1 is added bcz 1 space is mandatory 
                count++;
                j++;
            }

            if(j == n) { // last line should be left-justified
                string temp = "";

                for(int k = i; k < j; k++) {
                    temp += words[k];
                    if(k != j - 1) temp += ' ';
                }

                temp += string(maxWidth - temp.size(), ' ');
                ans.push_back(temp);
                break;
            }

            if(count == 1) {
                string temp = words[i];
                temp += string(maxWidth - words[i].size(), ' ');
                ans.push_back(temp);
                i = j;
                continue;
            }
            
            sz = sz - 1; // x words will have (x - 1) spaces
            int total_extra_spaces = maxWidth - sz;
            int extra_space = total_extra_spaces / (count - 1); // there will be (count - 1) empty places
            int bigs = total_extra_spaces % (count - 1); // this many components will have 1-1 extra space.

            // take the words from i to j-1.
            string temp = "";

            for(int k = i; k < j; k++) {
                temp += words[k];
                if(k != j - 1) temp += ' '; // mandatory space 
                if(bigs > 0 && k != j - 1) {
                    temp += string(extra_space + 1, ' '); // extra space 
                    bigs--;
                }
                else if(k != j - 1) temp += string(extra_space, ' '); // extra space
            }

            ans.push_back(temp);
            i = j;
        }

        return ans;
    }
};
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        int k = indices.size();

        vector<int> match(n, -1); // stores the operation i that can be applied at index 'index'

        for(int i = 0; i < k; i++) {
            int index = indices[i];
            string expected = sources[i];
            int sz = expected.size();

            string curr = s.substr(index, sz);
            if(curr != expected) continue;

            // if (curr == expected)
            match[index] = i;
        }

        int i = 0;
        string ans = "";
        
        while(i < n) {
            if(match[i] == -1) ans += s[i++];
            else {
                int op_index = match[i];
                ans += targets[op_index];
                i += sources[op_index].size();
            }
        }

        return ans;
    }
};
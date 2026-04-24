class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        vector<string> ans;

        for(auto q : queries) {
            int len = q.size();

            for(auto w : dictionary) {
                int edits = 0;
                for(int i = 0; i < len; i++) {
                    if(q[i] != w[i]) edits++;
                    if(edits > 2) break;
                }

                if(edits <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }

        return ans;
    }
};
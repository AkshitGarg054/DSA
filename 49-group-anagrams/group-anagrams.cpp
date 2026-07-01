class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, string>> vec;

        for(int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            vec.push_back({temp, strs[i]});
        }

        sort(vec.begin(), vec.end());

        vector<vector<string>> ans;
        vector<string> curr;
        curr.push_back(vec[0].second);

        for(int i = 1; i < n; i++) {
            string s1 = vec[i].first;
            string s2 = vec[i - 1].first;

            if(s1 == s2) curr.push_back(vec[i].second);
            else {
                ans.push_back(curr);
                curr.clear();
                curr.push_back(vec[i].second);
            }
        }

        ans.push_back(curr);
        return ans;
    }
};
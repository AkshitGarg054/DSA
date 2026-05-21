class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        unordered_set<string> st;

        for(int i = 0; i < n; i++) {
            string s = to_string(arr1[i]);
            for(int j = 0; j < s.size(); j++) {
                st.insert(s.substr(0, j+1));
            }
        }

        long long ans = 0;

        for(int i = 0; i < m; i++) {
            string s = to_string(arr2[i]);

            for(int j = 0; j < s.size(); j++) {
                string substring = s.substr(0, j+1);
                if(st.count(substring)) {
                    ans = max(ans, (long long)substring.size());
                }
            }
        }

        return ans;
    }
};
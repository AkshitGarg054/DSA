class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        vector<int> vec;

        int count = 1;
        for(int i = 1; i < n; i++) {
            char prev = word[i - 1];
            char ch = word[i];

            if(ch == prev) count++;
            else {
                vec.push_back(count);
                count = 1;
            }
        }

        vec.push_back(count);

        int ans = 1;
        for(int i = 0; i < vec.size(); i++) {
            int ele = vec[i];
            if(ele > 1) ans += (ele - 1);
        }

        return ans;
    }
};
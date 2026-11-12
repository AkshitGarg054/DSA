class Solution {
public:
    vector<string> strs;

    void solve(int prev, string &temp, int n, int k) {
        if(temp.size() == n) {
            strs.push_back(temp);
            return;
        }

        for(int i = 0; i <= 9; i++) {
            int diff = abs(i - prev);
            if(prev == -1 ? i != 0 : diff == k) {
                temp += (i + '0');
                solve(i, temp, n, k);
                temp.pop_back();
            } 
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        strs.clear();
        string temp = "";
        solve(-1, temp, n, k); 

        vector<int> ans;
        for(auto str: strs) ans.push_back(stoi(str));
        return ans;
    }
};
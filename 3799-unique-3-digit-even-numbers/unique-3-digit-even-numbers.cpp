class Solution {
public:
    unordered_set<int> st;

    void solve(vector<int> &temp, vector<int> &digits, vector<int> &vis) {
        if(temp.size() == 3) {
            if(temp[0] != 0 && temp[2] % 2 == 0) {
                int num = temp[0] * 100 + temp[1] * 10 + temp[2];
                st.insert(num);
            }
            return;
        } 

        for(int i = 0; i < digits.size(); i++) {
            if(vis[i]) continue;
            if(temp.empty() && digits[i] == 0) continue;

            temp.push_back(digits[i]);
            vis[i] = 1;

            solve(temp, digits, vis);

            temp.pop_back(); // backtrack
            vis[i] = 0;
        }        
    }

    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<int> vis(n, 0);
        vector<int> temp; 

        solve(temp, digits, vis);
        return st.size();
    }
};
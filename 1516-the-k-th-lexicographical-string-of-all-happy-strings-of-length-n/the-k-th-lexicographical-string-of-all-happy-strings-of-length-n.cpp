class Solution {
public:
    vector<string> ans;
    vector<char> vec = {'a', 'b', 'c'};

    void solve(string &temp, int index, int n, int k) {
        if(index == n) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < 3; i++) {
            if(temp.size() > 0 && temp.back() == vec[i]) continue;
            temp.push_back(vec[i]);
            solve(temp, index + 1, n, k); // we need to take index till n (so, increment index, not i)
            temp.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string temp = "";
        solve(temp, 0, n, k); // "" is temporary, so cannot pass "" directly coz we are accessing string &temp

        if(k > ans.size()) return "";
        return ans[k-1];
    }
};
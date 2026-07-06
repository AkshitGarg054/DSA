class Solution {
public:
    // important concept about backtracking of a string. (s.resize(oldSize) instead of s -= str)
    int maxi = INT_MIN;
    unordered_set<char> st;

    void solve(int index, vector<string> &arr, string &s) {
        if(index == arr.size()) {
            maxi = max(maxi, (int)s.size());
            return;
        }

        // skip
        solve(index + 1, arr, s);

        // take 
        bool unique = true;
        unordered_set<char> temp;

        // check if chars of arr[index] are already taken or not.
        // also, all chars in s[index] should be unique if we want to take it.
        for(auto &ch: arr[index]) {
            if(st.count(ch) || temp.count(ch)) {
                unique = false;
                break;
            }
            temp.insert(ch);
        }

        if(unique) {
            int oldSize = s.size();
            for(auto &ch: arr[index]) st.insert(ch);
            s += arr[index];

            solve(index + 1, arr, s);

            for(auto &ch: arr[index]) st.erase(ch); // backtracking
            s.resize(oldSize); // s -= arr[index] not possible
        }
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();

        string s = "";
        solve(0, arr, s);
        return maxi;
    }
};
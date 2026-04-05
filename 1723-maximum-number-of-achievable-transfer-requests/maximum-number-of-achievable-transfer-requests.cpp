class Solution {
public:
    int ans = 0;

    void solve(int index, int count, vector<int> &b, vector<vector<int>> &requests, int n) {
        if(index == requests.size()) {
            for(int i = 0; i < b.size(); i++) if(b[i] != 0) return; // this count is not valid, so jo abhi tk ans tha, vahi return krdo bss
            ans = max(ans, count);
            return;
        }

        // we can either take the request or reject it

        // not take
        solve(index + 1, count, b, requests, n);

        // take
        int from = requests[index][0], to = requests[index][1];  

        b[from]--, b[to]++;
        solve(index + 1, count + 1, b, requests, n);
        b[from]++, b[to]--; // backtrackk
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> b(n, 0);
        solve(0, 0, b, requests, n); // index, count  
        return ans;                              
    }
};
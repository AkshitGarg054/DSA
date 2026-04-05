class Solution {
public:
    int ans = 0;

    int solve(int index, vector<int> &b, vector<vector<int>> &requests, int n) {
        if(index == requests.size()) {
            for(int i = 0; i < b.size(); i++) if(b[i] != 0) return -1e9;
            return 0; // no more requests left 
        }

        // we can either take the request or reject it

        // not take
        int skip = 0 + solve(index + 1, b, requests, n);

        // take
        int from = requests[index][0], to = requests[index][1];  

        b[from]--, b[to]++;
        int take = 1 + solve(index + 1, b, requests, n);
        b[from]++, b[to]--; // backtrackk

        return max(take, skip);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> b(n, 0);
        int ans = solve(0, b, requests, n); // index, count  
        return ans;                              
    }
};
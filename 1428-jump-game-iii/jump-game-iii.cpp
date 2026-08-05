class Solution {
public:
    bool solve(int idx, vector<int>& arr, vector<int>& vis) {
        int n = arr.size();
        
        if(idx < 0 || idx >= n) return false;
        if(vis[idx]) return false;
        if(arr[idx] == 0) return true;

        vis[idx] = 1;

        bool pos = solve(idx + arr[idx], arr, vis);
        bool neg = solve(idx - arr[idx], arr, vis);

        return pos || neg;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);

        return solve(start, arr, vis);
    }
};
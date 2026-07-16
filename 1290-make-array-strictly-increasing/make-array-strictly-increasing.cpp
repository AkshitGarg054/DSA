class Solution {
public:
    // arr1 = [1, 5, 3, 6] 
    // arr2 = [1, 8, 9]
    // we can replace 5 or not replace 5
    // Replace 5: [1, 8, 9] --> we got no solution.
    // not replace 5: [1, 5, 8, 9] --> got solution

    unordered_map<string, int> dp;

    int solve(int index, int prev, vector<int> &arr1, vector<int> &arr2) {
        if(index == arr1.size()) return 0;

        string s = to_string(index) + "_" + to_string(prev);
        if(dp.count(s)) return dp[s];

        auto ub = upper_bound(arr2.begin(), arr2.end(), prev); // returns an iterator
        int ans = 1e9;
        
        if(arr1[index] <= prev) { // if curr is smaller than prev, then we must need to replace
            if(ub == arr2.end()) return 1e9;
            else ans = 1 + solve(index + 1, *ub, arr1, arr2);
        }
        else { // if curr is greater than prev, then we can replace it or not replace it
            int replace = 1e9;
            if(ub != arr2.end()) replace = 1 + solve(index + 1, *ub, arr1, arr2);
            int not_replace = solve(index + 1, arr1[index], arr1, arr2);
            ans = min(replace, not_replace);
        }

        return dp[s] = ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        if(n == 1) return 0;

        sort(arr2.begin(), arr2.end());

        int ans = solve(0, -1, arr1, arr2);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
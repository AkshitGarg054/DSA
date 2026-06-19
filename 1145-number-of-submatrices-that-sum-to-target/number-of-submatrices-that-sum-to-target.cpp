class Solution {
public:
    // here, we need to count the number of subarrays with sum = target
    int solve(vector<int> &arr, int target) {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1; // to handle subarrays that start from index 0

        int sum = 0;
        int count = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(mp.count(sum - target)) count += mp[sum - target];
            mp[sum]++;
        }

        return count;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for(int start = 0; start < n; start++) {
            vector<int> compressed(m, 0);

            for(int end = start; end < n; end++) {
                for(int col = 0; col < m; col++) compressed[col] += matrix[end][col];
                ans += solve(compressed, target);
            }
        }

        return ans;
    }
};
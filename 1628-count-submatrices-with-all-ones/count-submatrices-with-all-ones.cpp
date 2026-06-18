class Solution {
public:
    int solve(vector<int> &arr) {
        int ans = 0;
        int comulative = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) comulative = 0;
            else comulative++;

            ans += comulative;
        }

        return ans;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;

        for(int start = 0; start < n; start++) {
            vector<int> compressed(m, 1);

            for(int end = start; end < n; end++) {
                for(int col = 0; col < m; col++) compressed[col] = compressed[col] & mat[end][col];
                ans += solve(compressed);
            }
        }

        return ans;
    }
};
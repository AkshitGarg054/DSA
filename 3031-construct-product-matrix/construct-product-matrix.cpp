class Solution {
public:
    // Treat the 2D grid like a 1D array, and use the same idea as “product of array except self”.
    // To convert the 2D matrix into 1D array, we can use the trick to convert (i, j) into index = i * m + j
    // and, To convert the 1D array back into 2D grid, use the trick : row = index / m , col = index % m

    const int MOD = 12345;
    int n, m;
 
    int id(int i, int j) {
        return i * m + j;
    }

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int total = n * m;

        vector<int> arr(total); // convert 2D grid into 1D array
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int index = id(i, j);
                arr[index] = grid[i][j];
            }
        }

        vector<int> ans(total);

        // store prefix product in answer array directly
        ans[0] = 1; // do not include self
        for(int i = 1; i < total; i++) ans[i] = (1LL * ans[i-1] * arr[i-1]) % MOD;

        // store suffix product
        int suffix = 1;
        for(int i = total-1; i >= 0; i--) {
            ans[i] = (1LL * ans[i] * suffix) % MOD;
            suffix = (1LL * suffix * arr[i]) % MOD;
        }

        vector<vector<int>> p(n, vector<int>(m));

        for(int index = 0; index < total; index++) { // convert 1D array back to 2D
            int r = index / m;
            int c = index % m;
            p[r][c] = ans[index];
        }

        return p;
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int sum = img[i][j];
                int count = 1;

                for(auto d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if(ni >= 0 && nj >= 0 && ni < n && nj < m) {
                        sum += img[ni][nj];
                        count++;
                    }
                }

                ans[i][j] = sum / count;
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];
        if(color == original) return image;

        image[sr][sc] = color;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            int sz = q.size();
            bool found = false;

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(image[nr][nc] != original) continue;

                    if(image[nr][nc] == original) {
                        image[nr][nc] = color;
                        q.push({nr, nc});
                        found = true;
                    }
                }
            }

            if(found == false) break;
        }

        return image;
    }
};
class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<int> parent;
    vector<int> sz;

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;

        if(sz[px] > sz[py]) {
            parent[py] = px;
            sz[px] += sz[py];
        }
        else {
            parent[px] = py;
            sz[py] += sz[px];
        }
    }

    int id(int i, int j) {
        return i * m + j;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row;
        m = col;
        int LEFT = n*m;
        int RIGHT = n*m + 1;

        sz.resize(n*m + 2, 1);
        parent.resize(n*m + 2);
        for(int i = 0; i < parent.size(); i++) parent[i] = i;

        vector<vector<int>> grid(n, vector<int>(m, 0)); // initially entire land
        int days = 0;

        for(int i = 0; i < cells.size(); i++) {
            days++;
            int r = cells[i][0] - 1, c = cells[i][1] - 1; // converting cells to 0 based.

            if(grid[r][c] == 1) continue; // already water
            grid[r][c] = 1;

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(grid[nr][nc] == 0) continue;

                unite(id(r, c), id(nr, nc));
            }

            if(c == 0) unite(id(r, c), LEFT);
            if(c == m - 1) unite(id(r, c), RIGHT);

            if(find(LEFT) == find(RIGHT)) return days - 1;
        }

        return cells.size(); // if water bridge can't be formed from left to right.
    }
};
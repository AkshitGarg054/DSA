class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x + y) return false;
        if(target == 0) return true;

        set<pair<int, int>> vis;
        queue<pair<int, int>> q;
        q.push({0, 0}); // initially both empty

        while(!q.empty()) {
            auto [curr_x, curr_y] = q.front();
            q.pop();

            if(curr_x + curr_y == target) return true; 
            if (vis.count({curr_x, curr_y})) continue;
            vis.insert({curr_x, curr_y});

            q.push({x, curr_y});
            q.push({curr_x, y});
            q.push({0, curr_y});
            q.push({curr_x, 0});

            if(curr_x + curr_y <= x) q.push({curr_x + curr_y, 0});
            else q.push({x, curr_y - (x - curr_x)});

            if(curr_x + curr_y <= y) q.push({0, curr_x + curr_y});
            else q.push({curr_x - (y - curr_y), y});
        }

        return false;
    }
};
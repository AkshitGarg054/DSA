class Solution {
public:
    // we are given a target, we need to reach there in min number of steps
    // and we are giving multiple operations at each state
    // so, level order BFS will be applied

    int racecar(int target) {
        queue<pair<long long, long long>> q; // {position, speed}
        set<pair<long long, long long>> vis;

        q.push({0, 1});
        vis.insert({0, 1});

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                long long pos = q.front().first;
                long long speed = q.front().second;
                q.pop();

                if(pos == target) return steps;

                // for A
                long long posA = pos + speed;
                long long speedA = 1LL * speed * 2;

                // for R
                long long posR = pos;
                long long speedR;
                if(speed > 0) speedR = -1;
                else speedR = 1;

                if(abs(posA) <= 2 * target && abs(speedA) <= 2 * target && !vis.count({posA, speedA})) {
                    q.push({posA, speedA});
                    vis.insert({posA, speedA});
                }

                if(!vis.count({posR, speedR})) {
                    q.push({posR, speedR}); 
                    vis.insert({posR, speedR});
                }
            }

            steps++;
        }

        return steps;
    }
};
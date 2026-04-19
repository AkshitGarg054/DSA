class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<int> q;
        q.push(x);

        unordered_set<int> vis;
        vis.insert(x);

        int operations = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int curr = q.front();
                q.pop();

                if(curr == y) return operations;

                if(curr % 11 == 0) {
                    int next = curr / 11;
                    if(!vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }

                if(curr % 5 == 0) {
                    int next = curr / 5;
                    if(!vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }

                int inc = curr + 1;
                if(!vis.count(inc)) {
                    vis.insert(inc);
                    q.push(inc);
                }

                int dec = curr - 1;
                if(dec >= 0 && !vis.count(dec)) {
                    vis.insert(dec);
                    q.push(dec);
                }
            }

            operations++;
        }

        return -1;
    }
};
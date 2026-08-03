class Solution {
public:
    // xyzw can have 8 neighbors:
    // (x+1)yzw , (x-1)yzw
    // x(y+1)zw , x(y-1)zw
    // xy(z+1)w , xy(z-1)w
    // xyz(w+1) , xyz(w-1)

    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        unordered_set<string> st(deadends.begin(), deadends.end());

        unordered_set<string> vis;
        vis.insert("0000");

        string start = "0000";
        queue<string> q;
        q.push(start);

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string curr = q.front(); 
                q.pop();

                if(st.count(curr)) continue; // check any other sequence
                if(curr == target) return steps;

                for(int i = 0; i < 4; i++) { 
                    char original = curr[i];  
                    char up = (curr[i] == '9') ? '0' : curr[i] + 1;
                    char down = (curr[i] == '0') ? '9' : curr[i] - 1;

                    curr[i] = up;
                    if(!vis.count(curr)) {
                        q.push(curr); 
                        vis.insert(curr);
                    }

                    curr[i] = down;
                    if(!vis.count(curr)) {
                        q.push(curr); 
                        vis.insert(curr);
                    }

                    curr[i] = original;
                }
            }

            steps++;
        }

        return -1;
    }
};
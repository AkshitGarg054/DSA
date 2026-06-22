class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else {
                bool broken = false;

                while(!st.empty() && st.top() > 0) {
                    if(st.top() < abs(asteroids[i])) st.pop();
                    else if(st.top() == abs(asteroids[i])) {
                        st.pop();
                        broken = true;
                        break;
                    }
                    else { // this is when st.top() > abs(current)
                        broken = true; // current asteroid destroyed
                        break;
                    }
                }

                if((st.empty() || st.top() < 0) && !broken) st.push(asteroids[i]);
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
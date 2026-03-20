class Solution {
public:
    // for the current asteroid, we need just previous asteroid to check for collision
    // but we also need to store other previous asteroids to check for more collision
    // therefore, to store and remove the previous asteroids one by one, we need stack

    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(auto x : asteroids) {
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && x < 0) {
                if(st.top() < abs(x)) st.pop(); // prev explodes
                else if(st.top() == abs(x)) {
                    st.pop(); // both explodes
                    destroyed = true;
                    break; // break the loop when x explodes, and check for new x
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) st.push(x);
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
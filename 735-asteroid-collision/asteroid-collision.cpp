class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push(asteroids[i]);
                continue;
            }

            if(!st.empty() && asteroids[i] > 0 && st.top() > 0) st.push(asteroids[i]);
            else if(!st.empty() && (asteroids[i] < 0 || asteroids[i] > 0) && st.top() < 0) st.push(asteroids[i]); 
            else if(!st.empty() && asteroids[i] < 0 && st.top() > 0) {
                if(st.top() > abs(asteroids[i])) {
                    continue; // smaller one will explode
                }
                else if(st.top() == abs(asteroids[i])) st.pop(); // both will explode
                else {
                    while(!st.empty() && st.top() < abs(asteroids[i]) && st.top() > 0) st.pop(); // keep removing the smaller ones
                    if(st.empty() || st.top() < 0) st.push(asteroids[i]);
                    else if(st.top() == abs(asteroids[i])) st.pop();
                    // else, current destroyed
                }
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
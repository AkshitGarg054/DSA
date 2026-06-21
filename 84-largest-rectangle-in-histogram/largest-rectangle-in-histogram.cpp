class Solution {
public:
    // for every rectangle, we want the next smaller and the previous smaller
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int curr = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int width = nse - pse - 1;

                int area = width * heights[curr];
                ans = max(ans, area);
            }

            st.push(i);
        }

        while(!st.empty()) {
            int curr = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            int width = nse - pse - 1;

            int area = width * heights[curr];
            ans = max(ans, area);
        }

        return ans;
    }
};
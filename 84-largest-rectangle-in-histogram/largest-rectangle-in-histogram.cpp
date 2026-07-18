class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int curr = st.top();
                st.pop();

                int nse = i;
                int pse = (st.empty() ? -1 : st.top());

                int width = nse - pse - 1;
                int h = heights[curr]; 
                maxi = max(maxi, h * width);
            }

            st.push(i);
        }

        while(!st.empty()) {
            int curr = st.top();
            st.pop();

            int nse = n;
            int pse = (st.empty() ? -1 : st.top());
            
            int width = nse - pse - 1;
            int h = heights[curr]; 
            maxi = max(maxi, h * width);
        }

        return maxi;
    }
};
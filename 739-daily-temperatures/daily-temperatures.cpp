class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // nge
        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            if(nge[i] == -1) ans[i] = 0;
            else ans[i] = nge[i] - i;
        }

        return ans;
    }
};
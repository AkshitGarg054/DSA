class Solution {
public:
    const int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n), pse(n);
        stack<int> st;

        // nse -> next smaller element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // psee -> previous smaller or equal element (testcase: arr = [1, 1])
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop(); // equality sign won't come
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        int left, right;

        for(int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            ans = (ans + 1LL * left * right * arr[i]) % MOD;
        }

        return ans;
    }
};
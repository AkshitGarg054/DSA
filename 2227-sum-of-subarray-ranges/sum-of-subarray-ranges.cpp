class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n), pse(n), nge(n), pge(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) { // nse
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            else nse[i] = n;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++) { // pse
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            else pse[i] = -1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        long long sumMins = 0;
        for(int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            sumMins += 1LL * left * right * nums[i];
        }

        for(int i = n - 1; i >= 0; i--) { // nge
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(!st.empty()) nge[i] = st.top();
            else nge[i] = n;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++) { // pge
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(!st.empty()) pge[i] = st.top();
            else pge[i] = -1;
            st.push(i);
        }

        long long sumMaxi = 0;
        for(int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;
            sumMaxi += 1LL * left * right * nums[i];
        }

        return sumMaxi - sumMins;
    }
};
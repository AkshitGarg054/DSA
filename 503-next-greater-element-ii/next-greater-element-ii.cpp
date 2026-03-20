class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> nge(2*n, -1);
        stack<int> st; // store indices

        for(int i = 0; i < 2*n; i++) {
            while(!st.empty() && nums[i % n] > nums[st.top() % n]) {
                nge[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i] = nge[i];

        return ans;
    }
};
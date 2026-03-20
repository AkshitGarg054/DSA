class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // This vector is not used in this code, we can use it also.
        // If we use it, then there is no need to do (i % n)
        // vector<int> vec(nums.begin(), nums.end());
        // for(int i = 0; i < n; i++) vec.push_back(nums[i]);

        vector<int> nge(n, -1);
        stack<int> st; // store indices

        for(int i = 0; i < 2*n; i++) {
            while(!st.empty() && nums[i % n] > nums[st.top() % n]) {
                nge[st.top() % n] = nums[i % n];
                st.pop();
            }
            st.push(i);
        }

        return nge;
    }
};
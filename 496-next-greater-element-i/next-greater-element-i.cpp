class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> nge(m, -1);
        stack<int> st; // store indices

        for(int i = 0; i < m; i++) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                nge[st.top()] = nums2[i]; 
                st.pop();
            }
            st.push(i);
        }

        // store the position of each element of nums2
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++) mp[nums2[i]] = i;

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int ele = nums1[i];
            int index = mp[ele];
            ans[i] = nge[index];
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int ele = nums1[i];
            if(st1.count(ele) && st2.count(ele)) {
                ans.push_back(ele);
                st1.erase(ele);
                st2.erase(ele);
            }
        }

        return ans;
    }
};
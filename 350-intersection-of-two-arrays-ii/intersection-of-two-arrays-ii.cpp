class Solution {
public:
    // multiset stores duplicate elements, but st.erase(ele) erases all occurences of ele, not just one
    // to erase only one occurence, we use an iterator

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        multiset<int> st1(nums1.begin(), nums1.end());
        multiset<int> st2(nums2.begin(), nums2.end());

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int ele = nums1[i];
            
            auto it1 = st1.find(ele);
            auto it2 = st2.find(ele);

            if(it1 != st1.end() && it2 != st2.end()) {
                ans.push_back(ele);
                st1.erase(it1);
                st2.erase(it2);
            }
        }

        return ans;
    }
};
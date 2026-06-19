class Solution {
public:
    // approach 2: using set
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_set<int> st(arr.begin(), arr.end());
        int count = 0;

        for(int x = 1; ; x++) {
            if(!st.count(x)) {
                count++;
                if(count == k) return x;
            }
        }

        return -1;
    }
};
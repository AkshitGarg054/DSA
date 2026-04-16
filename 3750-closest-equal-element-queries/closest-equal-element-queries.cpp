class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        vector<int> vec(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) vec.push_back(nums[i]);

        unordered_map<int, int> mp1; // element --> index
        vector<int> next(2*n, -1);

        // left to right pass (to get the distance from 'next equal element')
        for(int i = 0; i < 2*n; i++) {
            int ele = vec[i];

            if(mp1.count(ele) && mp1[ele] != i) {
                int index = mp1[ele];
                if(i - index < n) next[index] = i - index;
                mp1[ele] = i;
            }
            else mp1[ele] = i;
        }

        unordered_map<int, int> mp2; // element --> index
        vector<int> prev(2*n, -1);

        // right to left pass (to get the distance from 'prev equal element')
        for(int i = 2*n - 1; i >= 0; i--) {
            int ele = vec[i];

            if(mp2.count(ele) && mp2[ele] != i) {
                int index = mp2[ele];
                if(index - i < n) prev[index] = index - i;
                mp2[ele] = i;
            }
            else mp2[ele] = i;
        }

        vector<int> ans;

        for(auto i : queries) {
            if(next[i] == -1 && prev[n + i] != -1) ans.push_back(prev[n + i]);
            else if(next[i] != -1 && prev[n + i] == -1) ans.push_back(next[i]);
            else ans.push_back(min(next[i], prev[n + i]));
        }

        return ans;
    }
};
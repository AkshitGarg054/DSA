class Solution {
public:
    // approach 1: using hash-map
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        cout << n << endl;

        map<int, int> mp;
        for(int i = 1; i <= n + k; i++) mp[i] = false; // (n + k) is the enough range to find an answer

        for(int i = 0; i < n; i++) {
            int ele = arr[i];
            mp[ele] = true;
        }

        int count = 0;
        for(auto [key, val]: mp) {
            if(val == false) {
                count++;
                if(count == k) return key;
            }
        }

        return -1;
    }
};
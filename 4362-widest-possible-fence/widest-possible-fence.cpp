class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();

        unordered_map<int, int> mp;
        int max_freq = INT_MIN;

        for(auto &ele: planks) {
            mp[ele]++;
            max_freq = max(max_freq, mp[ele]);
        }

        vector<int> unique; // store unique plank heights only to optimize the for nested for loops
        for(auto &[x, freq]: mp) unique.push_back(x);

        unordered_map<int, int> pairs;

        for(int i = 0; i < unique.size(); i++) {
            int h1 = unique[i];
            pairs[h1 * 2] += mp[h1] / 2;

            for(int j = i + 1; j < unique.size(); j++) {
                int h2 = unique[j];
                pairs[h1 + h2] += min(mp[h1], mp[h2]);
            }
        }

        int ans = max_freq; 

        for(auto &[h, count]: pairs) {
            int temp = count;
            if(mp.count(h)) temp += mp[h]; // add single planks
            ans = max(ans, temp);
        }

        return ans;
    }
};
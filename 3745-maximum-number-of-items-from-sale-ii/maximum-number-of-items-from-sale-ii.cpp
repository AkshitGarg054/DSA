class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int min_price = INT_MAX;
        int max_factor = INT_MIN;

        for(int i = 0; i < n; i++) {
            min_price = min(items[i][1], min_price);
            max_factor = max(items[i][0], max_factor);
        }

        // count factor frequencies to avoid the O(N^2) loop for creating the copies array
        vector<int> factor_count(max_factor + 1, 0);
        for(int i = 0; i < n; i++) factor_count[items[i][0]]++;

        // Collect pairs of {price, copies}
        vector<pair<int, int>> good_options;

        for(int i = 0; i < n; i++) {
            int f = items[i][0];
            int price = items[i][1];
            int count = 0;

            // step through multiple efficiently 
            for(int multiple = f; multiple <= max_factor; multiple += f) count += factor_count[multiple]; 
            count--; // exclude itself (i != j)

            // only consider it if it gives a free copy and beats the min_price efficiency  
            if(count > 0 && price < 2 * min_price) good_options.push_back({price, count});  
        }

        sort(good_options.begin(), good_options.end()); // sort by price

        int ans = 0;
        
        for(auto &option : good_options) {
            int price = option.first;
            int count = option.second;

            int take = min(budget / price, count); 
            ans += take * 2;
            budget -= take * price;
        }

        ans += budget / min_price; // extra items
        return ans;
    }
};

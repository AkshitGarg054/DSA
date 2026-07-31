class Solution {
public:
    // convert each row into end coordinates of each brick and see which value exists in maximum rows.
    // eg: [1, 2, 2, 1] ---> [1, 3, 5]
    // answer = n - number_of_rows_in_which_it_exists

    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();

        unordered_map<long long, int> mp;

        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                mp[sum]++;
            }
        }

        int maxi = 0; // maxi rows
        for(auto &[val, f]: mp) maxi = max(maxi, f);

        return n - maxi;
    }
};
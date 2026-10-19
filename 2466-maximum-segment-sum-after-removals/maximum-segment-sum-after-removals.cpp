class Solution {
public:
    vector<int> parent, sz;
    vector<long long> sum;
    vector<bool> active;

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;

        if(sz[px] > sz[py]) {
            parent[py] = px;
            sz[px] += sz[py];
            sum[px] += sum[py];
        }
        else {
            parent[px] = py;
            sz[py] += sz[px];
            sum[py] += sum[px];
        }
    }

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();

        sz.resize(n, 1);
        sum.resize(n, 0);
        active.assign(n, false);

        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        vector<long long> ans(n, 0);
        long long maxi = 0;

        for(int i = n - 1; i >= 0; i--) {
            ans[i] = maxi; // Record answer before adding this index back

            int index = removeQueries[i];

            active[index] = true;
            sum[index] = nums[index];
            maxi = max(maxi, sum[index]);

            if(index > 0 && active[index - 1]) { // merge with the active left neighbor
                unite(index - 1, index);
                maxi = max(maxi, sum[find(index)]); // sum[parent of index]
            }

            if(index < n - 1 && active[index + 1]) { // merge with active right neighbor
                unite(index, index + 1);
                maxi = max(maxi, sum[find(index)]);
            }
        }

        return ans;
    }
};
class Solution {
public:
    void build_min(int i, int l, int r, vector<int> &seg, vector<int> &nums) {
        if(l == r) {
            seg[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build_min(2*i + 1, l, mid, seg, nums);
        build_min(2*i + 2, mid + 1, r, seg, nums);
        
        seg[i] = min(seg[2*i + 1], seg[2*i + 2]);
    }

    void build_max(int i, int l, int r, vector<int> &seg, vector<int> &nums) {
        if(l == r) {
            seg[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build_max(2*i + 1, l, mid, seg, nums);
        build_max(2*i + 2, mid + 1, r, seg, nums);
        
        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }

    int query_min(int i, int start, int end, int l, int r, vector<int> &seg) {
        if(l > end || r < start) return INT_MAX;
        if(l >= start && r <= end) return seg[i];

        int mid = l + (r - l) / 2;
        return min(query_min(2*i + 1, start, end, l, mid, seg), query_min(2*i + 2, start, end, mid + 1, r, seg));
    }

    int query_max(int i, int start, int end, int l, int r, vector<int> &seg) {
        if(l > end || r < start) return INT_MIN;
        if(l >= start && r <= end) return seg[i];

        int mid = l + (r - l) / 2;
        return max(query_max(2*i + 1, start, end, l, mid, seg), query_max(2*i + 2, start, end, mid + 1, r, seg));
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();    
        priority_queue<pair<int, pair<int, int>>> pq; // max heap
 
        vector<int> segMin(4 * n);
        vector<int> segMax(4 * n);

        build_min(0, 0, n - 1, segMin, nums); // filling the segment tree array
        build_max(0, 0, n - 1, segMax, nums); // filling the segment tree array

        for(int l = 0; l < n-1; l++) {
            int mini = query_min(0, l, n - 1, 0, n - 1, segMin);
            int maxi = query_max(0, l, n - 1, 0, n - 1, segMax);
            pq.push({maxi - mini, {l, n - 1}});
        }

        // find top k
        long long ans = 0;

        while(k-- && !pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int value = it.first;
            int l = it.second.first;
            int r = it.second.second;

            ans += value;

            if(l <= r - 1) {
                long long new_min = query_min(0, l, r - 1, 0, n - 1, segMin);
                long long new_max = query_max(0, l, r - 1, 0, n - 1, segMax);
                long long new_value = new_max - new_min;
                pq.push({new_value, {l, r - 1}});
            }
        }

        return ans;
    }
};
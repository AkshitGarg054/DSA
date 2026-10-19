class Solution {
public:
    vector<int> tree;

    int query(int index, int start, int end, int l, int r, vector<int> &heights) {
        if(l > end || r < start) return -1;
        if(l >= start && r <= end) return tree[index];

        int mid = l + (r - l) / 2;
        int leftIndex = query(2*index + 1, start, end, l, mid, heights);
        int rightIndex = query(2*index + 2, start, end, mid + 1, r, heights);

        if(leftIndex == -1) return rightIndex;
        if(rightIndex == -1) return leftIndex;

        return (heights[leftIndex] > heights[rightIndex]) ? leftIndex : rightIndex;
    }

    void build_tree(int index, int l, int r, vector<int> &heights) {
        if(l == r) {
            tree[index] = l; // store the indices
            return;
        }

        int mid = l + (r - l) / 2;
        build_tree(2*index + 1, l, mid, heights);
        build_tree(2*index + 2, mid + 1, r, heights);

        int leftIndex = tree[2*index + 1];
        int rightIndex = tree[2*index + 2];

        tree[index] = (heights[leftIndex] > heights[rightIndex]) ? leftIndex : rightIndex;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> ans(queries.size());

        tree.resize(4*n);
        build_tree(0, 0, n - 1, heights);
        
        for(int i = 0; i < queries.size(); i++) {
            auto q = queries[i];
            int l = min(q[0], q[1]);
            int r = max(q[0], q[1]);

            if(l == r) ans[i] = l;
            else if(heights[r] > heights[l]) ans[i] = r;
            else {
                int start = r + 1;
                int end = n - 1;
                int index = INT_MAX;

                while(start <= end) {
                    int mid = start + (end - start) / 2;

                    int candidate = query(0, start, mid, 0, n - 1, heights);
                    if(heights[candidate] > max(heights[l], heights[r])) {
                        index = min(index, candidate);
                        end = mid - 1;
                    }
                    else start = mid + 1;
                }

                if(index == INT_MAX) ans[i] = -1;
                else ans[i] = index;
            }
        }

        return ans;
    }
};
class Solution {
public:
    // Ab is question me hm har ek query ke liye alg alg elements ka trie to nhi hi bnayenge.
    // we can try sorting the queries based on their 'm' values.
    // and also sort the nums array.
    // then, firr jitne elements current query ko chahiye utne hi ek time pe insert krenge trie me, 
    // and rest of the elements we can insert as the queries demands.

    struct Node {
        Node* links[2]; // 0, 1
    };

    Node* root = new Node();

    void insert(int num) {
        Node* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node -> links[bit] == NULL) node -> links[bit] = new Node();
            node = node -> links[bit];
        }
    }

    int getMax(int x) {
        int ans = 0;
        Node* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            // we need to search for the opposite bit
            if(node -> links[!bit] != NULL) {
                ans = ans | (1 << i);
                node = node -> links[!bit];
            }
            else node = node -> links[bit];
        }
        
        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // if we are sorting queries, then we also need to store original indices of queries.
        vector<vector<int>> qs;
        for(int i = 0; i < queries.size(); i++) qs.push_back({queries[i][1], queries[i][0], i});
        sort(qs.begin(), qs.end());

        vector<int> ans(queries.size()); 
        int index = 0; // index for nums array to always keep track of where we left off in the prev query.

        for(auto &q: qs) {
            int x = q[1];
            int limit = q[0];
            int original_index = q[2];

            while(index < n && nums[index] <= limit) {
                insert(nums[index]);
                index++;
            }

            if(index == 0) { // if no element has been inserted in the trie, like: nums = [5, 6], query = [2, 3]
                ans[original_index] = -1;
                continue;
            }

            int xorr = getMax(x);
            ans[original_index] = xorr;
        }

        return ans;
    }
};
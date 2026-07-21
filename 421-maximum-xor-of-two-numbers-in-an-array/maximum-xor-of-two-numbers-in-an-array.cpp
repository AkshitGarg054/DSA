class Solution {
public:
    struct Node {
        Node* links[2]; // 0, 1
    };

    Node* root = new Node(); // global node

    void insert(int num) {
        Node* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // check if ith bit is set or not
            if(node -> links[bit] == NULL) node -> links[bit] = new Node();
            node = node -> links[bit];
        }
    }

    int getMax(int x) { // returns max(x ^ nums[i]) where nums[i] are all numbers inserted in TRIE already.
        int ans = 0;
        Node* node = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1; 
            // we need to look for the opposite bit
            if(node -> links[!bit]) { // if opposite bit found
                ans = ans | (1 << i); 
                node = node -> links[!bit];
            }
            else node = node -> links[bit];
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) insert(nums[i]); // insert every nums[i] into TRIE.

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int temp = getMax(nums[i]);
            ans = max(ans, temp);
        }

        return ans;
    }
};
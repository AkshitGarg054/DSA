class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // rotate(first, middle, last) --> It rotates the range [first, last) so that middle becomes the first element.
        // vector<int> a = {1, 2, 3, 4, 5};
        // rotate(a.begin(), a.end() - 2, a.end());
        
        std::rotate(nums.begin(), nums.begin() + n - k, nums.end());
    }
};
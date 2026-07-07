class Solution {
public:
    vector<int> arr;

    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        int n = arr.size();
        vector<int> temp = arr;

        for(int i = 0; i < n; i++) {
            int index = rand() % n;
            swap(temp[i], temp[index]);
        }

        return temp;
    }
};
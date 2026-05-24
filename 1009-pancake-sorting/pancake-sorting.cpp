class Solution {
public:
    // If an operation modifies a prefix, process right-to-left. If it modifies a suffix, process left-to-right.
    // Find the largest element, flip it to the front, and then flip it to the very back (N). Now the largest element is locked at index N, and you pretend the array is just size N-1.

    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> seq;

        for(int sz = n; sz > 1; sz--) {
            // find the index of max element in the current unsorted prefix
            int max_index = 0;
            for(int i = 1; i < sz; i++) {
                if(arr[i] > arr[max_index]) max_index = i;
            }

            // if max element is already at its correct position
            if(max_index == sz - 1) continue;

            // move the max element to index zero
            if(max_index != 0) {
                seq.push_back(max_index + 1);
                reverse(arr.begin(), arr.begin() + max_index + 1);
            }

            // move the maximum element to its correct positon
            seq.push_back(sz);
            reverse(arr.begin(), arr.begin() + sz);
        }

        return seq;
    }
};
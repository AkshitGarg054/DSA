class Solution {
public:
    // This is the modification on count inversions problem.

    void merge(vector<pair<int, int>> &arr, int low, int mid, int high, vector<int> &count) {
        int left = low;
        int right = mid + 1;
        vector<pair<int, int>> temp;

        while(left <= mid && right <= high) {
            if(arr[left].first <= arr[right].first) {
                temp.push_back(arr[left]);

                int freq = right - (mid + 1);
                count[arr[left].second] += freq;

                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid) {
            count[arr[left].second] += right - (mid + 1);
            temp.push_back(arr[left++]);
        }

        while(right <= high) temp.push_back(arr[right++]);

        for(int i = low; i <= high; i++) arr[i] = temp[i - low];
    }

    void mergeSort(vector<pair<int, int>> &arr, int low, int high, vector<int> &count) {
        if(low < high) {
            int mid = low + (high - low) / 2;

            mergeSort(arr, low, mid, count);
            mergeSort(arr, mid + 1, high, count);
            merge(arr, low, mid, high, count);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> arr(n); // {value, index}
        for(int i = 0; i < n; i++) arr[i] = {nums[i], i};

        vector<int> count(n, 0);
        mergeSort(arr, 0, n - 1, count);
        return count;
    }
};
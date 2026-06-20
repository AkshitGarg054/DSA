class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(m == n) return n; // group of size n, only occurs at very last step

        vector<int> length(n + 2, 0);
        int count = 0; // count of m length substrings
        int latest = -1;

        for(int i = 0; i < n; i++) {
            int pos = arr[i];

            int left = length[pos - 1];
            int right = length[pos + 1];

            int new_len = left + right + 1;
            
            // update outer boundaries
            length[pos - left] = new_len;
            length[pos + right] = new_len;

            if(left == m) count--;
            if(right == m) count--;
            if(new_len == m) count++;

            if(count > 0) latest = i + 1;
        }

        return latest;
    }
};
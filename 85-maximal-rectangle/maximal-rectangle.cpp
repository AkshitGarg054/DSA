class Solution {
public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int curr = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;
                int h = arr[curr];
                maxi = max(maxi, width * h);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int curr = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int width = nse - pse - 1;
            int h = arr[curr];
            maxi = max(maxi, width * h);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Build the histogram matrix.
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) prefix[0][j] = matrix[0][j] - '0'; // first row

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0') prefix[i][j] = 0;
                else prefix[i][j] = prefix[i - 1][j] + 1;
            }
        }

        //  Now, find the largest rectangle for each row and choose the max of all.
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) ans = max(ans, largest(prefix[i]));

        return ans;
    }
};


// 1 0 1 0 0 --> x
// 2 0 2 1 1 --> y
// 3 1 3 2 2 --> z
// 4 0 0 3 0 --> w
// max(x, y, z, w)
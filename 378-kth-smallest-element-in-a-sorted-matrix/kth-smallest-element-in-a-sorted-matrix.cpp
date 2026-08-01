class Solution {
public:
    // Binary search on Answers.
    // Whenever we need to count the numbers in a matrix where rows and columns are sorted in ascending order, then we start count from matrix[n - 1][0] (bottom left corner).
    // If the current element is <= mid, it means everything above it in that column is also <= mid. We can instantly add that whole column chunk to our count and move one step right.
    // If the current element is > mid, it's too big, so we move one step up.
    int n, m;

    int solve(vector<vector<int>> &matrix, int mid) {
        int count = 0;
        int row = n - 1, col = 0;

        while(row >= 0 && col < m) {
            int value = matrix[row][col];

            if(value <= mid) {
                count += row + 1;
                col++;
            }
            else row--;
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        m = matrix[0].size();

        int low = matrix[0][0], high = matrix[n - 1][m - 1];
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int count = solve(matrix, mid); // find the no. of elements <= mid
            if(count >= k) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};
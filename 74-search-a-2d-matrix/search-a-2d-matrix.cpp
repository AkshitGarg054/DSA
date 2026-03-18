class Solution {
public:
    // see, in basic binary search, we need indices of elements for assigning low = 0, and high = n-1
    // so, in this 2d matrix also, hme indices chahiye honge
    // so, whenever 2d matrix ke indices ki need hme dikh rhi ho, then we already have a trick to get the index of a cell of grid
    // for a 1d index i --> 2d index => row = i / m , col = i % m 

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n*m - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int r = mid / m;
            int c = mid % m;

            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};
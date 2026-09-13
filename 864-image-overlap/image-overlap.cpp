class Solution {
public:
    // Let's say img2 is placed exactly on top of img1.
    // Ab hme img2 ke (n - 1)th column ko img1 ke 0th ke upar laana hai agr, to hme img2 ke (n-1)th col me se -(n-1) subtract krna pdega naa.
    // To ab, img2 k0 hm bilkul pura left se right iterate krenge jb tk hme overlap mil rha haii ...so we need to iterate from -(n-1) to (n-1) of img1.
    // kyuki, img2 ke 0th column ko img1 ke (n - 1) pe le jaane ke liye... +(n - 1) krenge

    int count(vector<vector<int>>& img1, vector<vector<int>>& img2, int row, int col, int n) {
        int overlap = 0;

        for(int i1 = 0; i1 < n; i1++) {
            for(int j1 = 0; j1 < n; j1++) {
                int i2 = i1 + row;
                int j2 = j1 + col;

                if(i2 < 0 || j2 < 0 || i2 >= n || j2 >= n) continue;
                if(img1[i1][j1] == 1 && img2[i2][j2] == 1) overlap++;
            }
        }

        return overlap;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();    
        int maxi = 0;

        for(int r = -(n - 1); r < n; r++) { // -(n-1) to +(n-1)
            for(int c = -(n - 1); c < n; c++) {
                maxi = max(maxi, count(img1, img2, r, c, n));
            }
        }

        return maxi;
    }
};
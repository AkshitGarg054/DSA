class Solution {
public:
    // Two rectangles overlap with +ve area if they overlap both horizontally and vertically.
    // (x1, y1), (x2, y2)       (a1, b1), (a2, b2)
    // Horizontal overlap: x1 < a2 && x2 > a1.
    // Vertical overlap: y1 < b2 && y2 > b1

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1];
        int x2 = rec1[2], y2 = rec1[3];
        int a1 = rec2[0], b1 = rec2[1];
        int a2 = rec2[2], b2 = rec2[3];

        if(x1 < a2 && x2 > a1 && y1 < b2 && y2 > b1) return true;
        return false;
    }
};
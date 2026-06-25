/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int n, m;

    bool check_same(int top, int bottom, int left, int right, vector<vector<int>>& grid) {
        int zeros = 0, ones = 0;

        for(int i = top; i <= bottom; i++) {
            for(int j = left; j <= right; j++) {
                if(grid[i][j] == 0) zeros++;
                else ones++;
            }
        }

        return (zeros == 0) || (ones == 0);
    }

    Node* build(int top, int bottom, int left, int right, vector<vector<int>>& grid) {
        if(check_same(top, bottom, left, right, grid)) return new Node(grid[top][left], true); // leaf node

        int mid_row = (top + bottom) / 2;
        int mid_col = (left + right) / 2;

        Node* root = new Node(0, false); // for a non-leaf node, the value can be 0 or 1 anything
        root -> topLeft = build(top, mid_row, left, mid_col, grid);
        root -> topRight = build(top, mid_row, mid_col + 1, right, grid);
        root -> bottomLeft = build(mid_row + 1, bottom, left, mid_col, grid);
        root -> bottomRight = build(mid_row + 1, bottom, mid_col + 1, right, grid);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        return build(0, n - 1, 0, m - 1, grid); // top, bottom, left, right
    }
};
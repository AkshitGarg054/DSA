class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1, 1});

        vector<int> curr = {1, 1};

        for(int k = 0; k < numRows - 2; k++) {
            vector<int> next;
            next.push_back(1);
            for(int i = 1; i < curr.size(); i++) next.push_back(curr[i] + curr[i - 1]);
            next.push_back(1);
            ans.push_back(next);
            curr = next;
        }

        return ans;
    }
};
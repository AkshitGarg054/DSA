class Solution {
public:
    // This code is having some edge case issue (try running this code on example 1).
    // The intervals [13, 23] and [24, 25] are merging together 
    // because as the [13, 23] ends, we add a -1 at 24, and as [24, 25] starts, we add a +1 at 24. 
    // To fix this, we need to something so that this -1 and +1 gets differentiated.
    // we must stop -1 and +1 from cancelling out each other.
    // so, instead of array, we'll use a vector<pair<int, int>> where vec[i].first is position and .second is +1 or -1
    // and we will then sort this vec. 
    // As if .first is same, then sorting will be done by seeing the second element, so -1 will be processed before +1.

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        if(n == 0 || m == 0) return {};

        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) {
            vec.push_back({firstList[i][0], 1});
            vec.push_back({firstList[i][1] + 1, -1});
        }

        for(int i = 0; i < m; i++) {
            vec.push_back({secondList[i][0], 1});
            vec.push_back({secondList[i][1] + 1, -1});
        }

        sort(vec.begin(), vec.end()); // sorted 

        int start = -1;
        int prev = -1; // prev value 

        vector<vector<int>> ans;
        int sum = 0;

        for(int i = 0; i < vec.size(); i++) {
            sum += vec[i].second;
            if(sum == 2 && prev != 2) start = vec[i].first;
            if(sum != 2 && prev == 2) ans.push_back({start, vec[i].first - 1});
            prev = sum;
        }

        return ans;
    }
};
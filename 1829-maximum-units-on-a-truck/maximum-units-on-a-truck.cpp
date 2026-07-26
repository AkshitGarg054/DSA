class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        // sort on the basis of units in descending order
        sort(boxTypes.begin(), boxTypes.end(), [&](auto &a, auto &b) {
            return a[1] > b[1];
        });

        int ans = 0;

        for(auto &box: boxTypes) {
            int count = box[0];
            int units = box[1];

            if(count <= truckSize) {
                ans += units * count;
                truckSize -= count;
            }
            else {
                ans += units * truckSize;
                return ans;
            }
        }

        return ans;
    }
};
class Solution {
public:
    // This problem is best solved using backtracking + recursion.
    // The idea is to repeatedly choose two numbers, apply an operator, and replace those two numbers with the result. Continue until only one number remains.
    // If only one number remains and it equals 24, return true.

    bool solve(vector<double> &nums) {
        if(nums.size() == 1) {
            return abs(nums[0] - 24.0) <= 1e-6;
        }

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                vector<double> remaining;

                for(int k = 0; k < n; k++) {
                    if(k != i && k != j) remaining.push_back(nums[k]);
                }

                double a = nums[i];
                double b = nums[j];

                vector<double> results = {a - b, a + b, b - a, a * b};
                if(abs(b) > 1e-6) results.push_back(a / b);
                if(abs(a) > 1e-6) results.push_back(b / a);

                for(auto result: results) {
                    remaining.push_back(result);
                    if(solve(remaining)) return true;
                    remaining.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
class Solution {
public:
    // As here we are adding two strings and we want the addition to be lexicographically largest
    // So, we must sort such that :
    // For two strings a and b, if (a + b) > (b + a) --> then, a should come before b

    string largestNumber(vector<int>& nums) {
        int n = nums.size();  

        vector<string> vec(n);
        for(int i = 0; i < n; i++) vec[i] = to_string(nums[i]);

        sort(vec.begin(), vec.end(), [&](string &a, string &b) {
            return a + b > b + a;
        });

        string ans = "";
        for(auto s : vec) ans += s;

        if(ans[0] == '0') return "0"; // for [0, 0, 0]
        return ans;
    }
};
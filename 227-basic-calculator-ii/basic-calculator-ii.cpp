class Solution {
public:
    int calc(int a, int b, char sign) {
        int ans;
        if(sign == '+') return a + b;
        if(sign == '-') return a - b;
        if(sign == '*') return a * b;
        return a / b;
    }

    void solve(vector<int> &nums, vector<char> &signs, char s1, char s2) {
        vector<int> num;
        vector<char> s;

        for(int i = 0; i < signs.size(); i++) {
            if(signs[i] != s1 && signs[i] != s2) {
                num.push_back(nums[i]);
                s.push_back(signs[i]);
            }
            else {
                nums[i + 1] = calc(nums[i], nums[i + 1], signs[i]);
            }
        }

        num.push_back(nums.back());

        nums = num;
        signs = s;
    }

    int calculate(string s) {
        int n = s.size();
        
        string temp = ""; // string without extra spaces
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') temp += s[i];
        }

        vector<int> nums;
        vector<char> signs;
        string number;

        for(int i = 0; i < temp.size(); i++) {
            char ch = temp[i];

            if(isdigit(ch)) number += ch;
            else {
                int num = stoi(number);
                nums.push_back(num);
                signs.push_back(ch);
                number = "";
            }
        }

        nums.push_back(stoi(number));

        solve(nums, signs, '/', '*');
        solve(nums, signs, '+', '-');

        return nums.back();
    }
};
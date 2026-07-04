class Solution {
public:
    // start from left to right and if num[i] > num[i + 1] then we have to delete num[i].
    // removing one digit can create a new inversion that also needs to be removed.
    // example: "25613" ...after removing 6, 5 also needs to be removed.
    // that is why, this ques needs a stack.

    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        
        stack<char> st;
        st.push(num[0]);
        int removed = 0;

        int i = 1;
        while(i < n) {
            while(!st.empty() && st.top() > num[i] && removed < k) {
                st.pop();
                removed++;
            }
            st.push(num[i]);
            i++;
        }

        int remaining = k - removed;

        // if k is still greater than 0, then we need to remove elements from end of string
        // example: 123456, k = 3 --> then, answer = 123
        string ans = "";
        while(!st.empty()) {
            if(remaining == 0) {
                ans += st.top();
                st.pop();
            }
            else {
                st.pop();
                remaining--;
            }
        }

        // now reverse the string answer and remove leading zeros.
        reverse(ans.begin(), ans.end());

        int index = -1;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] != '0') {
                index = i;
                break;
            }
        }

        if(index == -1) return "0"; // all are zeros
        return ans.substr(index);
    }
};
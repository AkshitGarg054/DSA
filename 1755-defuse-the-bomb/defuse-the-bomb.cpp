class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> prefix(2*n + 1);
        prefix[0] = code[0];
        for(int i = 1; i < 2*n; i++) prefix[i] = prefix[i-1] + code[i % n];

        vector<int> ans(n, 0);

        if(k > 0) {
            for(int i = 0; i < n; i++) {
                int sum = prefix[i + k] - prefix[i];
                ans[i] = sum;
            }
        }
        else if(k < 0) {
            k = -k;
            for(int i = n; i < 2*n; i++) {   
                int sum = prefix[i-1] - prefix[i-k-1];
                ans[i - n] = sum;
            }
        }
        
        return ans;
    }
};
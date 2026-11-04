class Solution {
public:
    int beautySum(string s) {
        int n = s.size();  
        int sum = 0;

        for(int i = 0; i < n; i++) { // i is the start of any substring
            vector<int> freq(26, 0); 

            for(int j = i; j < n; j++) {
                char ch = s[j];
                freq[ch - 'a']++;

                int maxi = 0;
                int mini = 1e9;

                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};
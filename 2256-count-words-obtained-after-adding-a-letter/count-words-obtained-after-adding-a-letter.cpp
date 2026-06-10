class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> st; // store masks for each start word

        for(auto word : startWords) {
            int mask = 0;
            for(char ch : word) {
                int pos = ch - 'a';
                mask = mask | (1 << pos);
            }

            st.insert(mask);
        }

        int ans = 0;

        for(auto word : targetWords) {
            int mask = 0;
            for(char ch : word) {
                int pos = ch - 'a';
                mask = mask | (1 << pos);
            }

            // try removing each char from the mask one by one 
            for(char ch : word) {
                int pos = ch - 'a';
                int new_mask = mask ^ (1 << pos); // xor is used to unset a set bit

                if(st.count(new_mask)) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};
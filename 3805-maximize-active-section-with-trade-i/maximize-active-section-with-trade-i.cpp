class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        if(ones == 0) return 0;
        if(ones == n) return n;
        
        vector<pair<char, int>> vec; // {char -> start_index}

        char curr = s[0];
        vec.push_back({curr, 0});
        int i = 1;

        // s = "001110001100" --> vec = {{0, 0}, {1, 2}, {0, 5}, {1, 8}, {0, 10}}
        while(i < n) {
            char ch = s[i];

            if(ch != curr) {
                curr = ch;
                vec.push_back({curr, i});
            }

            i++;
        }

        vector<int> prefix(n, 0); // prefix array for storing the count of ones
        prefix[0] = (s[0] == '1');
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + (s[i] == '1');

        // we need to search for any of the sequences: 010, 1010, 0101, 10101
        // and return the seq of max size out of all these.

        // to handle cases like: "01", "10", "100" etc
        // we need to check whether there exists a sequence of "010" in vec or not, as "010" is must for all our 4 required sequences.
        bool possible = false;
        for(int i = 1; i < vec.size() - 1; i++) {
            if(vec[i - 1].first == '0' && vec[i].first == '1' && vec[i + 1].first == '0') {
                possible = true;
                break;
            }
        }

        if(!possible) return ones;


        if(vec.size() == 3) {
            if(vec[0].first == '0' && vec[1].first == '1' && vec[2].first == '0') {
                int len = s.size() - vec[0].second;
                return len;
            }
        }

        int m = vec.size();
        int maxi = 0;

        // vec.size() is >= 4
        for(int i = 0; i < vec.size(); i++) {
            char ch = vec[i].first;
            int index = vec[i].second;
            int len = 0;
            int left = -1, right = -1;

            if(ch == '0') { // search for 010 or 0101 sequence
                if(i + 3 < m && vec[i + 1].first == '1' && vec[i + 2].first == '0' && vec[i + 3].first == '1') { // 0101
                    if(i + 4 < m) {
                        len = vec[i + 4].second - index;
                        left = index, right = vec[i + 4].second - 1;
                    }
                    else {
                        len = s.size() - index;
                        left = index, right = s.size() - 1;
                    }
                }
                else if(i + 2 < m && vec[i + 1].first == '1' && vec[i + 2].first == '0') { // 010
                    if(i + 3 < m) {
                        len = vec[i + 3].second - index;
                        left = index, right = vec[i + 3].second - 1;
                    }
                    else {
                        len = s.size() - index;
                        left = index, right = s.size() - 1;
                    }
                }
            }
            else if(ch =='1') { // search for 1010 or 10101
                if(i + 4 < m && vec[i + 1].first == '0' && vec[i + 2].first == '1' && vec[i + 3].first == '0' && vec[i + 4].first == '1') { // 10101
                    if(i + 5 < m) {
                        len = vec[i + 5].second - index;
                        left = index, right = vec[i + 5].second - 1;
                    }
                    else {
                        len = s.size() - index;
                        left = index, right = s.size() - 1;
                    }
                }
                else if(i + 3 < m && vec[i + 1].first == '0' && vec[i + 2].first == '1' && vec[i + 3].first == '0') { // 1010
                    if(i + 4 < m) {
                        len = vec[i + 4].second - index;
                        left = index, right = vec[i + 4].second - 1;
                    }
                    else {
                        len = s.size() - index;
                        left = index, right = s.size() - 1;
                    }
                }
            }

            // Now, till this point, we are doing one mistake.
            // we are only counting the 1s that we obtained after applying the operation.
            // we also need to count the remaining 1s in the string.
            // For example: s = "10100101". Here we get our pattern of length 6 but the remaining string contains one more 1, so final answer is 7, not 6.

            if(left == -1) continue;
            
            int inside = prefix[right];
            if(left > 0) inside -= prefix[left - 1];
            int remaining = ones - inside;

            maxi = max(maxi, len + remaining);
        }

        return maxi;
    }
};
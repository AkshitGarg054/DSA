class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        while(true) {
            vector<pair<int, char>> vec = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
            sort(vec.rbegin(), vec.rend()); // sort in descending order
            bool added = false;

            for(auto it : vec) {
                int count = it.first;
                char ch = it.second;

                if(count == 0) continue; // can't use it more
                
                int n = ans.size();
                // can't use any char more than 2 times
                if(n >= 2 && ans[n-1] == ch && ans[n-2] == ch) continue;

                // use the char
                ans += ch;

                if(ch == 'a') a--;
                else if(ch == 'b') b--;
                else c--;

                added = true;
                break;
            }

            if(!added) break; 
        }
        
        return ans;
    }
};
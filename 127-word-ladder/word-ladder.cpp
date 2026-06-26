class Solution {
public:
    // Why we need to mark the visited??
    // If a word has already been discovered by BFS once, there is never any benefit in discovering it again later.
    // because BFS explores level by level, the first time you discover any word, you've already found the shortest possible path to it.

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return 0;
        st.insert(beginWord);

        queue<string> q;
        q.push(beginWord);
        int level = 1; // to count beginWord

        while(!q.empty()) {
            int sz = q.size();
            
            while(sz--) {
                string curr = q.front(); 
                q.pop();

                if(curr == endWord && st.count(curr)) return level;
                st.erase(curr); // works as a visited marker (to prevent hit -> hot -> hit -> hot....)

                for(int i = 0; i < curr.size(); i++) {
                    int ch = curr[i]; 

                    for(char c = 'a'; c <= 'z'; c++) {
                        if(ch == c) continue;
                        curr[i] = c; 
                        if(st.count(curr)) q.push(curr);
                    }

                    curr[i] = ch; // undo 
                }
            }

            level++;
        }

        return 0;
    }
};
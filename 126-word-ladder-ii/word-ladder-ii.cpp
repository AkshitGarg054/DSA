class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent; // {word} --> {its parents}

    void dfs(string word, string beginWord, vector<string> &path) {
        path.push_back(word);

        if(word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else {
            for(auto &p: parent[word]) dfs(p, beginWord, path);
        }

        path.pop_back(); // backtrack
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.insert(beginWord);
        if(!st.count(endWord)) return ans;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> vis;
        vis.insert(beginWord);

        bool found = false;

        while(!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVis;

            while(sz--) {
                auto curr = q.front();
                q.pop();

                for(int i = 0; i < curr.size(); i++) {
                    char ch = curr[i];
                    string original = curr;

                    for(char c = 'a'; c <= 'z'; c++) {
                        if(ch == c) continue;
                        curr[i] = c;

                        if(st.count(curr) && !vis.count(curr)) {
                            if(!levelVis.count(curr)) {
                                q.push(curr);
                                levelVis.insert(curr);
                            }
                            parent[curr].push_back(original);
                        }

                        if(curr == endWord) found = true;
                    }

                    curr[i] = ch;
                }
            }

            for(auto &it: levelVis) vis.insert(it);
        }

        vector<string> path;
        dfs(endWord, beginWord, path);
        return ans;
    }
};
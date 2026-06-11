class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        parent[px] = py;
    }

    bool similar(string &s, string &t) {
        int diff = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) diff++;
            if(diff > 2) return false;
        }

        if(diff == 0 || diff == 2) return true;
        return false; 
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i; 
        
        // create connected components
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(similar(strs[i], strs[j])) unite(i, j);
            }
        }

        // count connected components
        int groups = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i) groups++;
        }

        return groups;
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();

        map<vector<int>, int> mp;
        for(auto it: dominoes) mp[it]++;

        int pairs = 0;

        for(int i = 0; i < n; i++) {
            vector<int> p1 = dominoes[i];
            vector<int> p2 = {dominoes[i][1], dominoes[i][0]};

            pairs--; // remove counting itself
            if(mp.count(p1)) pairs += mp[p1]; 
            if(p1 != p2 && mp.count(p2)) pairs += mp[p2];
        }

        return pairs / 2; // each pair was getting counted twice
    }
};


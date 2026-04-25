class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        
        vector<pair<int, int>> stones;
        for(int i = 0; i < n; i++) stones.push_back({aliceValues[i], bobValues[i]});

        sort(stones.begin(), stones.end(), [&](auto &a, auto &b) {
            return a.first + a.second > b.first + b.second; // sort in desc order by alice_value + bob_value
        });

        int alice = 0, bob = 0;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) { // first turn is of alice, so he will pick all even indices
                alice += stones[i].first;
            }
            else bob += stones[i].second;
        }

        if(alice > bob) return 1;
        if(alice < bob) return -1;
        return 0;
    }
};
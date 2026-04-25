class Solution {
public:
    // when a stone i is picked, Alice gains aliceValues[i] and Bob loses the chance to gain bobValues[i]
    // so total impact of picking a stone = aliceValues[i] + bobValues[i]
    // combine values : total[i] = aliceValues[i] + bobValues[i]
    // sort stones in descending order of total 
    // then start alternate picking : alice picks at even turns and bob picks at odd turns

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
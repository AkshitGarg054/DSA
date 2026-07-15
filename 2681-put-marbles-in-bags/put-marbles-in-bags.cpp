class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1 || k == n) return 0; // only one possible distribution, so diff = 0

        vector<long long> pairs;
        for(int i = 0; i < n - 1; i++) pairs.push_back((long long)weights[i] + weights[i + 1]);
        sort(pairs.begin(), pairs.end());

        long long mini = 0;
        long long maxi = 0;

        for(int i = 0; i < k-1; i++) mini += pairs[i];
        for(int i = 0; i < k-1; i++) maxi += pairs[pairs.size() - 1 - i];

        return maxi - mini;
    }
};
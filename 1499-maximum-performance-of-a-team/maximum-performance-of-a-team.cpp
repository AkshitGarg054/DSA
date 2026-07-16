class Solution {
public:
    const int MOD = 1e9 + 7;

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers(n);
        for(int i = 0; i < n; i++) engineers[i] = {efficiency[i], speed[i]};

        // sort by efficiency in decreasing order
        sort(engineers.rbegin(), engineers.rend());

        priority_queue<int, vector<int>, greater<>> pq; // min heap (always store top k elements only)
        long long sum = 0, maxi = 0;

        for(auto &[e, s]: engineers) {
            pq.push(s);
            sum += s;

            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            maxi = max(maxi, sum * e);
        }

        return maxi % MOD;
    }
};  
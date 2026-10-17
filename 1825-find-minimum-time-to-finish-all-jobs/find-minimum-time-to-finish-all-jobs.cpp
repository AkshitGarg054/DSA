class Solution {
public:
    int ans = INT_MAX;

    void f(int ind, vector<int> &workers, vector<int> &jobs, int k) {
        if(ind == jobs.size()) {
            int maxi = 0;
            for(int i=0; i < k; i++) maxi = max(workers[i], maxi);
            ans = min(ans, maxi);
            return;
        }

        for(int i = 0; i < k; i++) {
            workers[i] += jobs[ind];
            if (*max_element(workers.begin(), workers.end()) < ans) f(ind + 1, workers, jobs, k);
            workers[i] -= jobs[ind];
            if(workers[i] == 0) break;
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> workers(k, 0);
        f(0, workers, jobs, k);
        return ans;
    }
};
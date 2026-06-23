class Solution {
public:
    // basically, jo task hmne currently kra haii, usko k time ke liye kahin side pe rakhdo
    // aur firr k time pura hone ke baad vapis le aao

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto ch: tasks) mp[ch]++;
        
        priority_queue<int> pq; // max heap
        for(auto it: mp) pq.push(it.second);

        queue<pair<int, int>> q; // {freq, time when it will go to pq}
        int time = 0;

        while(!pq.empty()) {
            int maxi = pq.top();
            pq.pop();

            maxi--;
            time++;
            if(maxi > 0) q.push({maxi, time + n});

            if(pq.empty() && q.size() > 0) {
                int wait = q.front().second - time;
                time += wait; // idle time added
            }

            if(q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
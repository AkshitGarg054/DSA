class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto &ch: tasks) mp[ch]++;

        priority_queue<int> pq; // max heap
        for(auto &it: mp) pq.push(it.second);

        queue<pair<int, int>> q; // {freq, time when it will come back}
        int time = 0;
    
        while(!pq.empty()) {
            int freq = pq.top();
            pq.pop();

            time++;
            freq--;
            if(freq > 0) q.push({freq, time + n});

            if(pq.empty() && q.size() > 0) {
                int wait = q.front().second - time;
                time += wait; // idle time
            }

            if(q.front().second == time) {
                int f = q.front().first;
                q.pop();
                pq.push(f);
            }
        }

        return time;
    }
};
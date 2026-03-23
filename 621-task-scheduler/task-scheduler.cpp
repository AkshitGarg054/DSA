class Solution {
public:
    // we always try to pick (n+1) elements from the heap, kyuki hme n ka gap chahiye
    // agar (n+1) elements mil rhe hnn, fir to boht badhiaa
    // aur agar nhi mil rhee, to remaining needed elements ke liye idle process add krdo

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto ch : tasks) mp[ch]++;

        priority_queue<int> pq; // to extract maximum frequencies
        for(auto it : mp) pq.push(it.second);

        int count = 0;
        
        while(!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            while(cycle && !pq.empty()) {
                int f = pq.top();
                pq.pop();
                if(f - 1 > 0) temp.push_back(f - 1);
                count++, cycle--;
            }

            for(int x : temp) pq.push(x);
            
            if(!pq.empty()) count += cycle; // add remaining cycle as idle time if (n+1) unique processes were not there
        }

        return count;
    }
};
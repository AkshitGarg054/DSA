class Solution {
public:
    // ye bhi "Distribution pattern" jaisa hi haiii
    // bss isme ek aisa haii ki hme lexicographically largest chahiye ...so, largest freq wale ki jagah largest character wala pehle daalenge
    // as, hme har baar largest char chahiye, so max heap for getting largest char
    // and hme har char ki freq bhi chahiye, so unordered_map to store freq
    // algo -
    // take the largest available char
    // use it as much as allowed
    // if it still remains, insert next smaller char to break the streak
    // continue again

    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();

        unordered_map<char, int> mp;
        for(auto ch : s) mp[ch]++;

        priority_queue<char> pq; // max heap
        for(auto [ch, freq] : mp) pq.push(ch); // pushing only unique chars into heap

        string largest = "";

        while(!pq.empty()) {
            char maxi = pq.top();
            pq.pop();

             // use maxi as much as possible
            int use = min(mp[maxi], repeatLimit);
            largest += string(use, maxi);
            mp[maxi] -= use;

            // if maxi are still left
            if(mp[maxi] > 0) {
                if(pq.empty()) break; // no separater available

                char smaller = pq.top();
                pq.pop();

                largest += smaller;
                mp[smaller]--;

                if(mp[smaller] > 0) pq.push(smaller);
                pq.push(maxi);
            }
        }

        return largest;
    }
};
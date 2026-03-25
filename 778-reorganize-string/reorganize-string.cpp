class Solution {
public:
    // here also, we don't want any any two adjacent characters to be same.
    // so, to create such a string where this arrangement is possible --
    // start by placing the most frequent characters first
    // use max heap (as we need to dynamically update the frequencies of chars)
    // Because if you just used 'a', you should not use it again immediately,
    // so keep it outside the heap for one turn. This automatically enforces, no adjacent duplicates

    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto ch : s) mp[ch]++;

        priority_queue<pair<int, char>> pq; // use max heap, to always get the char with max freq
        for(auto [ch, count] : mp) pq.push({count, ch});

        string ans = "";
        pair<int, char> prev = {0, '#'};

        while(!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();

            ans += ch;
            freq--;
            if(prev.first > 0) pq.push(prev); // now, prev char can be reused

            prev = {freq, ch};
        }

        if(ans.size() != s.size()) return ""; // "aaab"
        return ans;
    }
};
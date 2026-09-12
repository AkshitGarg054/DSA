class Solution {
public:
    // jis jis point pe height change ho rhi haii hme vo vo points save krne hn, aur us point pe max height ko rakhna hai.
    // aur height change hmesha start ya end points pe hi ho skti haii, so sabhi start aur end points ko ikatha krlo aur un points pe kya kya height hai, vo note krlo.
    // when a building is ending, we don't consider that height.
    // we need to keep track of the active buildings at any point x, and choose the max height from those active buildings.

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<int, int>> events; // {position, height}: (start, -h) and (end, h)

        for(int i = 0; i < n; i++) {
            int s = buildings[i][0], e = buildings[i][1], h = buildings[i][2];
            events.push_back({s, -h});
            events.push_back({e, h});
        }

        sort(events.begin(), events.end()); // sort on the basis of position

        int prev_maxi = 0;
        multiset<int> st; // we could also use PQ. But we need to remove the building when it ends and in PQ we can only remove the top element. To remove any element easily, we are using multiset.
        st.insert(0);

        vector<vector<int>> ans; // we only push into answer, when the maxi changes.
        
        for(int i = 0; i < events.size(); i++) {
            int pos = events[i].first;
            int h = events[i].second;

            if(h < 0) st.insert(-h);
            else st.erase(st.find(h)); // st.erase(h) removes all occurences of h

            int maxi = *st.rbegin();
            if(maxi != prev_maxi) { // maxi changed
                ans.push_back({pos, maxi});
                prev_maxi = maxi;
            }
        }

        return ans;
    }
};
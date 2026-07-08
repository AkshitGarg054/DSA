class Solution {
public:
    // As we have limited number of prisons (8) and each prison can take only two values, so there can be only 2^8 = 256 configurations.
    // So, we are guaranteed that the state will definitely repeat after some days.
    // So, we can start from day 1 and keep storing the states with their day, as soon as we get a repeated state, we detected a cycle.

    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int sz = cells.size();
        map<vector<int>, int> mp; // state, day
        mp[cells] = 0; // day 0
        
        vector<int> ans(sz);
        vector<int> temp = cells;

        int day = 1;
        while(day <= n) {
            ans[0] = 0;
            ans[sz - 1] = 0;

            for(int j = 1;  j < sz-1; j++) {
                if(temp[j - 1] == temp[j + 1]) ans[j] = 1;
                else ans[j] = 0;
            }

            if(!mp.count(ans)) mp[ans] = day;
            else {
                int started = mp[ans];
                int today = day;
                int cycle_length = today - started;
                int remaining = n - today;
                remaining = remaining % cycle_length;
                day = n - remaining;
            }

            temp = ans;
            day++;
        }

        return ans;
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<long long> roomAvailableAt(n, 0);
        vector<int> count(n, 0);

        for(auto &meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            bool found = false;

            long long minEnd = LLONG_MAX;
            int minEndIdx = -1;

            for(int room = 0; room < n; room++) {
                if(roomAvailableAt[room] <= start) {
                    roomAvailableAt[room] = end; // current meeting assigned to this room
                    count[room]++;
                    found = true;
                    break; // jaise hi room mil gya, then break krdo
                }

                if(roomAvailableAt[room] < minEnd) { // to find which room gets free-ed earliest
                    minEnd = roomAvailableAt[room];
                    minEndIdx = room;
                }
            }

            if(!found) { // if free room is not found --> meeting needs to be delayed
                roomAvailableAt[minEndIdx] += duration;
                count[minEndIdx]++;
            }
        }

        int ans = -1;
        int maxUsed = 0;
        for(int i = 0; i < n; i++) {
            if(count[i] > maxUsed) {
                maxUsed = count[i];
                ans = i;
            }
        }

        return ans;
    }
};
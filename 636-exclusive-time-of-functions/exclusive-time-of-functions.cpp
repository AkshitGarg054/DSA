class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<int, int>> st; // id, time

        for(auto &log: logs) {
            int colon1 = log.find(':');
            int colon2 = log.rfind(':');

            int id = stoi(log.substr(0, colon1));
            string type = log.substr(colon1 + 1, colon2 - colon1 - 1);
            int time = stoi(log.substr(colon2 + 1));

            if(type == "start") {
                if(!st.empty()) ans[st.top().first] += time - st.top().second;
                st.push({id, time}); 
            }
            else {
                ans[st.top().first] += time - st.top().second + 1; // ending at t means it also convered t
                st.pop();
                if(!st.empty()) st.top().second = time + 1; // the last function will resume at time + 1
            }
        }

        return ans;
    }
};
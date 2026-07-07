class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<string> letterLogs, digitLogs;

        for(int i = 0; i < n; i++) {
            string log = logs[i];

            // find the first space in log.
            int index = log.find(' ');
            index = index + 1; // index to be checked

            if(isdigit(log[index])) digitLogs.push_back(log);
            else letterLogs.push_back(log);
        }

        // sort the letter logs
        sort(letterLogs.begin(), letterLogs.end(), [&](auto &a, auto &b) {
            int index_a = a.find(' ') + 1;
            int index_b = b.find(' ') + 1;
            string str1 = a.substr(index_a), str2 = b.substr(index_b);
            string id1 = a.substr(0, index_a - 1), id2 = b.substr(0, index_b - 1);

            if(str1 == str2) return id1 < id2;
            return str1 < str2; 
        });

        for(int i = 0; i < digitLogs.size(); i++) letterLogs.push_back(digitLogs[i]);
        return letterLogs;
    }
};
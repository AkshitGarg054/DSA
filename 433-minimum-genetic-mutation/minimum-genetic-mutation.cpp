class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if(!st.count(endGene)) return -1;

        queue<string> q;
        q.push(startGene);
        st.erase(startGene);

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string curr = q.front();
                q.pop();

                if(endGene == curr) return steps;

                for(int i = 0; i < 8; i++) {
                    char original = curr[i];

                    if(original != 'A') {
                        curr[i] = 'A';
                        if(st.count(curr)) {
                            q.push(curr);
                            st.erase(curr); // mark as visited
                        }
                    }
                    if(original != 'C') {
                        curr[i] = 'C';
                        if(st.count(curr)) {
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    if(original != 'G') {
                        curr[i] = 'G';
                        if(st.count(curr)) {
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    if(original != 'T') {
                        curr[i] = 'T';
                        if(st.count(curr)) {
                            q.push(curr);
                            st.erase(curr);
                        }
                    }

                    curr[i] = original;
                }
            }

            steps++;
        }

        return -1;
    }
};
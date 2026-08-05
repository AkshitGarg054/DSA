class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses; 
        vector<vector<int>> list(n);
        vector<int> indegree(n, 0);

        for(auto &edge: prerequisites) {
            int u = edge[1];
            int v = edge[0];
            list[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for(auto &v: list[node]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        if(count == n) return true;
        return false;
    }
};
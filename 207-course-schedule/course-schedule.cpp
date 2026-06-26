class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> list(n);
        vector<int> indegree(n);

        for(auto edge: prerequisites) {
            int u = edge[1], v = edge[0];
            list[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it: list[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(ans.size() == n) return true;
        return false;
    }
};
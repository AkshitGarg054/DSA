class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);

        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while(!q.empty()) {
            int index = q.front();
            q.pop();

            if(arr[index] == 0) return true;

            int next = index + arr[index];
            if(next < n && !vis[next]) {
                q.push(next);
                vis[next] = 1;
            }

            next = index - arr[index];
            if(next >= 0 && !vis[next]) {
                q.push(next);
                vis[next] = 1;
            }
        }

        return false;
    }
};
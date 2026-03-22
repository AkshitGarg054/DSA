class Solution {
public:
    // assume, every value as a node
    // as for each value arr[i], we can go to i - arr[i] and i + arr[i]
    // means each value has two paths (or choices), ...those two values will again have two paths
    // looks like a tree --> traverse its levels like level order BFS

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        bool zero = false;
        for(int i =  0; i < n; i++) {
            if(arr[i] == 0) {
                zero = true;
                break;
            }
        }

        if(zero == false) return false;

        queue<int> q;
        vector<bool> vis(n, false); // to mark the index as visited, otherwise we'll keep visiting again n again
        q.push(start);
        vis[start] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            if(arr[curr] == 0) return true;

            // get the left and right index
            int left = curr - arr[curr];
            int right = curr + arr[curr];

            if(left >= 0 && !vis[left]) { 
                q.push(left);
                vis[left] = true;
            }

            if(right < n && !vis[right]) { 
                q.push(right);
                vis[right] = true;
            }
        }

        return false;
    }
};
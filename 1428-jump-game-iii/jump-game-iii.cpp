class Solution {
public:
    vector<int> vis;

    bool dfs(vector<int> &arr, int index) {
        vis[index] = 1; 
        if(arr[index] == 0) return true;

        int left = index - arr[index];
        int right = index + arr[index];

        if(left >= 0 && !vis[left] && dfs(arr, left)) return true;
        if(right < arr.size() && !vis[right] && dfs(arr, right)) return true;

        return false;
    }

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

        vis.resize(n, 0);
        return dfs(arr, start);
    }
};
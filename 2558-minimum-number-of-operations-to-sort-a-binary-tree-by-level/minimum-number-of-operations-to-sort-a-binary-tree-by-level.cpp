class Solution {
public:
    int count_operations(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int> mp; // element -> index
        for(int i = 0; i < n; i++) mp[arr[i]] = i;
        
        int swaps = 0;
        
        for(int i = 0; i < n; i++) {
            int ele = arr[i];
            int required = temp[i];
            if(ele == required) continue;
            
            int index = mp[required];
            
            swap(arr[i], arr[index]);
            swaps++;
            
            mp[ele] = index;
            mp[required] = i; // required came at i
        }
        
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();
            vector<int> vec;

            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();

                vec.push_back(curr -> val);

                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }

            ans += count_operations(vec);
        }

        return ans;
    }
};
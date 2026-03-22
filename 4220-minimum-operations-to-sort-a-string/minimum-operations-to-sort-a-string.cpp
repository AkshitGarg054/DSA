class Solution {
public:
    bool isSorted(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] > s[i + 1]) return false;
        }

        return true;
    }

    int minOperations(string s) {
        int n = s.size();
        if(isSorted(s)) return 0;
        if(n == 2) return -1;

        char mini = s[0], maxi = s[0];
        for (char c : s) {
            mini = min(mini, c);
            maxi = max(maxi, c);
        }

        if (s[0] == mini || s[n - 1] == maxi) return 1;
        if (s[0] == maxi && s[n - 1] == mini) {
            // for s = "oool"
            bool mini_elsewhere = false;
            bool maxi_elsewhere = false;
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == mini) mini_elsewhere = true;
                if (s[i] == maxi) maxi_elsewhere = true;
            }
            
            if (mini_elsewhere || maxi_elsewhere) return 2;
            return 3;
        }
        return 2;
    }
};